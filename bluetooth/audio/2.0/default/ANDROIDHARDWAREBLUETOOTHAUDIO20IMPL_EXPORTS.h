#pragma once

#if defined(WIN32) || defined(_MSC_VER)

#if defined(ANDROIDHARDWAREBLUETOOTHAUDIO20IMPL_EXPORTS_IMPL)
#define ANDROIDHARDWAREBLUETOOTHAUDIO20IMPL_API __declspec(dllexport)
#else
#define ANDROIDHARDWAREBLUETOOTHAUDIO20IMPL_API __declspec(dllimport)
#endif  // defined(ANDROIDHARDWAREBLUETOOTHAUDIO20IMPL_EXPORTS_IMPL)

#else  // defined(WIN32)
#if defined(ANDROIDHARDWAREBLUETOOTHAUDIO20IMPL_EXPORTS_IMPL)
#define ANDROIDHARDWAREBLUETOOTHAUDIO20IMPL_API __attribute__((visibility("default")))
#else
#define ANDROIDHARDWAREBLUETOOTHAUDIO20IMPL_API
#endif  // defined(ANDROIDHARDWAREBLUETOOTHAUDIO20IMPL_EXPORTS_IMPL)
#endif

#ifdef _WIN32
#ifdef interface
#undef interface
#endif
#endif
