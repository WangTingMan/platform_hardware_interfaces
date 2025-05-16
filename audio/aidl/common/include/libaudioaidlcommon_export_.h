#pragma once

#if defined(WIN32) || defined(_MSC_VER)

#if defined(LIBAUDIOAIDLCOMMON_EXPORTS)
#define LIBAUDIOAIDLCOMMON_API __declspec(dllexport)
#else
#define LIBAUDIOAIDLCOMMON_API __declspec(dllimport)
#endif  // defined(LIBAUDIOAIDLCOMMON_EXPORTS)

#else  // defined(WIN32)
#if defined(LIBAUDIOAIDLCOMMON_EXPORTS)
#define LIBAUDIOAIDLCOMMON_API __attribute__((visibility("default")))
#else
#define LIBAUDIOAIDLCOMMON_API
#endif  // defined(LIBAUDIOAIDLCOMMON_EXPORTS)
#endif

#ifdef __cplusplus
#ifndef __BEGIN_DECLS
#define __BEGIN_DECLS extern "C" {
#endif
#else
#define __BEGIN_DECLS
#endif

#ifdef __cplusplus
#ifndef __END_DECLS
#define __END_DECLS }
#endif
#else
#define __END_DECLS
#endif

#ifndef ssize_t
#define ssize_t int64_t
#endif
