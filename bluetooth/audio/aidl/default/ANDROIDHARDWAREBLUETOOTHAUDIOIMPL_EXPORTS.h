#pragma once

#if defined(WIN32) || defined(_MSC_VER)

#if defined(ANDROIDHARDWAREBLUETOOTHAUDIOIMPL_EXPORTS_IMPL)
#define ANDROIDHARDWAREBLUETOOTHAUDIOIMPL_EXPORTS_API __declspec(dllexport)
#else
#define ANDROIDHARDWAREBLUETOOTHAUDIOIMPL_EXPORTS_API __declspec(dllimport)
#endif  // defined(ANDROIDHARDWAREBLUETOOTHAUDIOIMPL_EXPORTS_IMPL)

#else  // defined(WIN32)
#if defined(ANDROIDHARDWAREBLUETOOTHAUDIOIMPL_EXPORTS_IMPL)
#define ANDROIDHARDWAREBLUETOOTHAUDIOIMPL_EXPORTS_API __attribute__((visibility("default")))
#else
#define ANDROIDHARDWAREBLUETOOTHAUDIOIMPL_EXPORTS_API
#endif  // defined(ANDROIDHARDWAREBLUETOOTHAUDIOIMPL_EXPORTS_IMPL)
#endif

ANDROIDHARDWAREBLUETOOTHAUDIOIMPL_EXPORTS_API void ANDROIDHARDWAREBLUETOOTHAUDIOIMPL_TEST_NOT_USE_DIRECTLY();

#ifdef _WIN32
#ifdef interface
#undef interface
#endif
#endif
