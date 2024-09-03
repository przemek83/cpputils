#pragma once

// clang-format off

#if defined(_WIN32) || defined(_WIN64)
    #ifdef CPPUTILS_SHARED_LIB
        #ifdef CPPUTILS_BUILD_LIB
            #define CPPUTILS_API __declspec(dllexport)
        #else
            #define CPPUTILS_API __declspec(dllimport)
        #endif
    #else
        #define CPPUTILS_API
    #endif
#else
    #define CPPUTILS_API
#endif

// clang-format onS
