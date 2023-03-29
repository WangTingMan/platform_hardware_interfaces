#pragma once

#if defined(WIN32) || defined(_MSC_VER)

#if defined(LIBBLUETOOTHAUDIOSESSION_EXPORTS_IMPL)
#define LIBBLUETOOTHAUDIOSESSION_EXPORTS __declspec(dllexport)
#else
#define LIBBLUETOOTHAUDIOSESSION_EXPORTS __declspec(dllimport)
#endif  // defined(LIBBLUETOOTHAUDIOSESSION_EXPORTS_IMPL)

#else  // defined(WIN32)
#if defined(LIBBLUETOOTHAUDIOSESSION_EXPORTS_IMPL)
#define LIBBLUETOOTHAUDIOSESSION_EXPORTS __attribute__((visibility("default")))
#else
#define LIBBLUETOOTHAUDIOSESSION_EXPORTS
#endif  // defined(LIBBLUETOOTHAUDIOSESSION_EXPORTS_IMPL)
#endif

#ifdef _WIN32
#ifdef interface
#undef interface
#endif
#endif
