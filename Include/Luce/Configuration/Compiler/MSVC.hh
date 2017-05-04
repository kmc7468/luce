#ifndef LUCE_HEADER_CONFIGURATION_COMPILER_MSVC_HH
#define LUCE_HEADER_CONFIGURATION_COMPILER_MSVC_HH
#include <Luce/Configuration/Basic-Value.hh>
#include <Luce/Configuration/Compiler-Value.hh>

#ifdef LUCE_CONFIG_COMPILER
#error The compiler configuration is invalid.
#endif

#define LUCE_CONFIG_COMPILER LUCE_CONFIG_MSVC

#define LUCE_CONFIG_LINUX_SUPPORTED LUCE_CONFIG_NO
#define LUCE_CONFIG_UNIX_SUPPORTED LUCE_CONFIG_NO
#define LUCE_CONFIG_WINDOWS_SUPPORTED LUCE_CONFIG_YES

#include <Luce/Configuration/Platform/Windows.hh>

#if _MSC_VER >= 1900 // Visual C++ 2015 (14.0, 19.0)
#define LUCE_CONFIG_CONSTEXPR LUCE_CONFIG_YES
#define LUCE_CONFIG_NOEXCEPT LUCE_CONFIG_YES
#else
#define LUCE_CONFIG_CONSTEXPR LUCE_CONFIG_NO
#define LUCE_CONFIG_NOEXCEPT LUCE_CONFIG_NO
#endif

#if _MSC_VER >= 1700 // Visual C++ 2012 (11.0, 17.0)
#define LUCE_CONFIG_FINAL LUCE_CONFIG_YES
#define LUCE_CONFIG_OVERRIDE LUCE_CONFIG_YES
#else
#define LUCE_CONFIG_FINAL LUCE_CONFIG_NO
#define LUCE_CONFIG_OVERRIDE LUCE_CONFIG_NO
#endif

#if _MSC_VER >= 1600 // Visual C++ 2010 (10.0, 16.0)
#define LUCE_CONFIG_RLALUE_REFERENCE LUCE_CONFIG_YES
#define LUCE_CONFIG_STATICASSERT LUCE_CONFIG_YES
#else
#define LUCE_CONFIG_RLALUE_REFERENCE LUCE_CONFIG_NO
#define LUCE_CONFIG_STATICASSERT LUCE_CONFIG_NO
#endif

#endif