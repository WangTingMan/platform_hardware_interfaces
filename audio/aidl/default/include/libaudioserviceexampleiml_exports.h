#pragma once
#if defined(WIN32) || defined(_MSC_VER)

#if defined(LIBAUDIOSERVICEEXAMPLEIMPL_EXPORTS)
#define LIBAUDIOSERVICEEXAMPLEIMPL_API __declspec(dllexport)
#else
#define LIBAUDIOSERVICEEXAMPLEIMPL_API __declspec(dllimport)
#endif  // defined(LIBAUDIOSERVICEEXAMPLEIMPL_EXPORTS)

#else  // defined(WIN32)
#if defined(LIBAUDIOSERVICEEXAMPLEIMPL_EXPORTS)
#define LIBAUDIOSERVICEEXAMPLEIMPL_API __attribute__((visibility("default")))
#else
#define LIBAUDIOSERVICEEXAMPLEIMPL_API
#endif  // defined(LIBAUDIOSERVICEEXAMPLEIMPL_EXPORTS)
#endif

