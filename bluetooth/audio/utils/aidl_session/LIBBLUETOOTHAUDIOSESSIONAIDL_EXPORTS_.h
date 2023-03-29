#pragma once

#if defined(WIN32) || defined(_MSC_VER)

#if defined(LIBBLUETOOTHAUDIOSESSIONAIDL_EXPORTS_IMPL)
#define LIBBLUETOOTHAUDIOSESSIONAIDL_EXPORTS __declspec(dllexport)
#else
#define LIBBLUETOOTHAUDIOSESSIONAIDL_EXPORTS __declspec(dllimport)
#endif  // defined(LIBBLUETOOTHAUDIOSESSIONAIDL_EXPORTS_IMPL)

#else  // defined(WIN32)
#if defined(LIBBLUETOOTHAUDIOSESSIONAIDL_EXPORTS_IMPL)
#define LIBBLUETOOTHAUDIOSESSIONAIDL_EXPORTS __attribute__((visibility("default")))
#else
#define LIBBLUETOOTHAUDIOSESSIONAIDL_EXPORTS
#endif  // defined(LIBBLUETOOTHAUDIOSESSIONAIDL_EXPORTS_IMPL)
#endif

#ifdef _WIN32
#ifdef interface
#undef interface
#endif
#endif
