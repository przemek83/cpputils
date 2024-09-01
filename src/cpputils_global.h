#pragma once


#if defined(_WIN32) || defined(_WIN64)
    #ifdef CPPUTILS_LIBRARY
        #define CPPUTILS_API __declspec(dllexport)
    #else
        #define CPPUTILS_API __declspec(dllimport)
    #endif
#else
    #define CPPUTILS_API
#endif