#pragma once

// clang-format off

#if defined(CPPUTILS_SHARED_LIB) && (defined(_WIN32) || defined(_WIN64))
    #ifdef CPPUTILS_BUILD_LIB
        #define CPPUTILS_API __declspec(dllexport)
    #else
        #define CPPUTILS_API __declspec(dllimport)
    #endif
#else
    #define CPPUTILS_API
#endif

// clang-format onS
