#ifndef ASHIBA_INCLUDE_MACRO_HPP
#define ASHIBA_INCLUDE_MACRO_HPP

#if !defined(ASHIBA_PLATFORM_WINDOWS)
    && !defined(ASHIBA_PLATFORM_LINUX)
    && !defined(ASHIBA_PLATFORM_MACOS)
    #if defined(_WIN32)
        #define ASHIBA_PLATFORM_WINDOWS 1
    #elif defined(__APPLE__)
        #define ASHIBA_PLATFORM_MACOS 1
    #elif defined(__linux__)
        #define ASHIBA_PLATFORM_LINUX 1
    #endif
#endif

#if !defined(ASHIBA_COMPILER_MSVC)
    && !defined(ASHIBA_COMPILER_CLANG)
    && !defined(ASHIBA_COMPILER_GCC)
    #if defined(_MSC_VER)
        #define ASHIBA_COMPILER_MSVC 1
    #elif defined(__clang__)
        #define ASHIBA_COMPILER_CLANG 1
    #elif defined(__GNUC__)
        #define ASHIBA_COMPILER_GCC 1
    #endif
#endif

#if defined(ASHIBA_COMPILER_WINDOWS)
    #if defined(ASHIBA_BUILD_SHARED)
        #define ASHIBA_EXPORT __declspec(dllexport)
        #define ASHIBA_IMPORT __declspec(dllimport)
    #else
        #define ASHIBA_EXPORT
        #define ASHIBA_IMPORT
    #endif
#else
    #if defined(ASHIBA_BUILD_SHARED)
        #define ASHIBA_EXPORT __attribute__((visibility("default")))
        #define ASHIBA_IMPORT __attribute__((visibility("default")))
    #else
        #define ASHIBA_EXPORT
        #define ASHIBA_IMPORT       
    #endif
#endif

#endif // ASHIBA_INCLUDE_MACRO_HPP