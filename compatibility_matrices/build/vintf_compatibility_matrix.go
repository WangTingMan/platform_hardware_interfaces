// Copyright (C) 2018 The Android Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

package vintf

import (
	"fmt"
	"io"
	"strings"

	"github.com/google/blueprint"
	"github.com/google/blueprint/proptools"

	"android/soong/android"
	"android/soong/kernel/configs"
)

type dependencyTag struct {
	blueprint.BaseDependencyTag
	name string
}

var (
	pctx = android.NewPackageContext("android/vintf")

	assembleVintfRule = pctx.AndroidStaticRule("assemble_vintf", blueprint.RuleParams{
		Command:     `${assembleVintfCmd} -i ${inputs} -o ${out} ${extraParams}`,
		CommandDeps: []string{"${assembleVintfCmd}"},
		Description: "assemble_vintf -i ${inputs}",
	}, "inputs", "extraParams")

	xmllintXsd = pctx.AndroidStaticRule("xmllint-xsd", blueprint.RuleParams{
		Command:     `$XmlLintCmd --quiet --schema $xsd $in > /dev/null && touch -a $out`,
		CommandDeps: []string{"$XmlLintCmd"},
		Restat:      true,
	}, "xsd")

	kernelConfigTag  = dependencyTag{name: "kernel-config"}
	schemaTag        = dependencyTag{name: "matrix-schema"}
	schemaModuleName = "compatibility_matrix_schema"
)

const (
	relpath = "vintf"
)

type vintfCompatibilityMatrixProperties struct {
	// set the name of the output
	Stem *string

	// list of source compatibility matrix XML files
	Srcs []string

	// list of kernel_config modules to be combined to final output
	Kernel_configs []string

	// Default is "default" for compatibility matrices on /vendor
	// and /odm, and "disallow" for compatibility matrices on /system,
	// /product, and /system_ext.
	// If value is "only", only android.* HALs are allowed. If value
	// is "disallow", none of android.* HALs are allowed.
	Core_hals *string
}

type vintfCompatibilityMatrixRule struct {
	android.ModuleBase
	properties vintfCompatibilityMatrixProperties

	genFile                android.WritablePath
	additionalDependencies android.WritablePaths
}

func init() {
	pctx.HostBinToolVariable("assembleVintfCmd", "assemble_vintf")
	pctx.HostBinToolVariable("XmlLintCmd", "xmllint")
	android.RegisterModuleType("vintf_compatibility_matrix", vintfCompatibilityMatrixFactory)
}

func vintfCompatibilityMatrixFactory() android.Module {
	g := &vintfCompatibilityMatrixRule{}
	g.AddProperties(&g.properties)
	android.InitAndroidArchModule(g, android.DeviceSupported, android.MultilibCommon)
	return g
}

var _ android.AndroidMkDataProvider = (*vintfCompatibilityMatrixRule)(nil)

func (g *vintfCompatibilityMatrixRule) DepsMutator(ctx android.BottomUpMutatorContext) {
	android.ExtractSourcesDeps(ctx, g.properties.Srcs)
	ctx.AddDependency(ctx.Module(), kernelConfigTag, g.properties.Kernel_configs...)
	ctx.AddDependency(ctx.Module(), schemaTag, schemaModuleName)
}

func (g *vintfCompatibilityMatrixRule) timestampFilePath(ctx android.ModuleContext, path android.Path) android.WritablePath {
	return android.GenPathWithExt(ctx, "vintf-xmllint", path, "ts")
}

func (g *vintfCompatibilityMatrixRule) generateValidateBuildAction(ctx android.ModuleContext, path android.Path, schema android.Path) {
	timestamp := g.timestampFilePath(ctx, path)
	ctx.Build(pctx, android.BuildParams{
		Rule:        xmllintXsd,
		Description: "xmllint-xsd",
		Input:       path,
		Output:      timestamp,
		Implicit:    schema,
		Args: map[string]string{
			"xsd": schema.String(),
		},
	})
	g.additionalDependencies = append(g.additionalDependencies, timestamp)
}

func (g *vintfCompatibilityMatrixRule) getSchema(ctx android.ModuleContext) android.OptionalPath {
	schemaModule := ctx.GetDirectDepWithTag(schemaModuleName, schemaTag)
	sfp, ok := schemaModule.(android.SourceFileProducer)
	if !ok {
		ctx.ModuleErrorf("Implicit dependency %q has no srcs", ctx.OtherModuleName(schemaModule))
		return android.OptionalPath{}
	}

	schemaSrcs := sfp.Srcs()
	if len(schemaSrcs) != 1 {
		ctx.PropertyErrorf(`srcs of implicit dependency %q has length %d != 1`, ctx.OtherModuleName(schemaModule), len(schemaSrcs))
		return android.OptionalPath{}
	}
	return android.OptionalPathForPath(schemaSrcs[0])
}

func (g *vintfCompatibilityMatrixRule) GenerateAndroidBuildActions(ctx android.ModuleContext) {

	outputFilename := proptools.String(g.properties.Stem)
	if outputFilename == "" {
		outputFilename = g.Name()
	}

	schema := g.getSchema(ctx)
	if !schema.Valid() {
		return
	}

	inputPaths := android.PathsForModuleSrc(ctx, g.properties.Srcs)
	for _, srcPath := range inputPaths {
		g.generateValidateBuildAction(ctx, srcPath, schema.Path())
	}

	// No need to validate matrices from kernel configs because they are generated by
	// assemble_vintf.
	ctx.VisitDirectDepsWithTag(kernelConfigTag, func(m android.Module) {
		if k, ok := m.(*configs.KernelConfigRule); ok {
			inputPaths = append(inputPaths, k.OutputPath())
		} else {
			ctx.PropertyErrorf("kernel_configs",
				"module %q is not a kernel_config", ctx.OtherModuleName(m))
		}
	})

	g.genFile = android.PathForModuleGen(ctx, outputFilename)

	ctx.Build(pctx, android.BuildParams{
		Rule:        assembleVintfRule,
		Description: "Framework Compatibility Matrix",
		Implicits:   inputPaths,
		Output:      g.genFile,
		Args: map[string]string{
			"inputs":      strings.Join(inputPaths.Strings(), ":"),
			"extraParams": strings.Join(g.getExtraParams(), " "),
		},
	})
	g.generateValidateBuildAction(ctx, g.genFile, schema.Path())

	ctx.InstallFile(android.PathForModuleInstall(ctx, "etc", relpath), outputFilename, g.genFile)
}

func (g *vintfCompatibilityMatrixRule) AndroidMk() android.AndroidMkData {
	return android.AndroidMkData{
		Class:      "ETC",
		OutputFile: android.OptionalPathForPath(g.genFile),
		Extra: []android.AndroidMkExtraFunc{
			func(w io.Writer, outputFile android.Path) {
				fmt.Fprintln(w, "LOCAL_MODULE_RELATIVE_PATH :=", relpath)
				if proptools.String(g.properties.Stem) != "" {
					fmt.Fprintln(w, "LOCAL_MODULE_STEM :=", proptools.String(g.properties.Stem))
				}
				for _, path := range g.additionalDependencies {
					fmt.Fprintln(w, "LOCAL_ADDITIONAL_DEPENDENCIES +=", path.String())
				}
			},
		},
	}
}

// Return extra parameters to assemble_vintf.
func (g *vintfCompatibilityMatrixRule) getExtraParams() []string {
	var extraParams []string

	coreHalsStrategy := proptools.StringDefault(
		g.properties.Core_hals,
		g.defaultCoreHalsStrategy(),
	)
	extraParams = append(extraParams, "--core-hals", proptools.ShellEscape(coreHalsStrategy))
	return extraParams
}

func (g *vintfCompatibilityMatrixRule) defaultCoreHalsStrategy() string {
	// TODO(b/290408770): default to "disallow" for FCMs

	// For Device (vendor, odm) compatibility matrix, default is
	// to not check anything.
	return "default"
}
