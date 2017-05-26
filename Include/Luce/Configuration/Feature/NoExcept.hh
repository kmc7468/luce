#ifndef LUCE_HEADER_CONFIGURATION_FEATURE_NOEXCEPT_HH
#define LUCE_HEADER_CONFIGURATION_FEATURE_NOEXCEPT_HH
#include <Luce/Configuration/Basic-Value.hh>

#if LUCE_MACRO_IS_YES(LUCE_CONFIG_NOEXCEPT) 
#define LUCE_MACRO_NOEXCEPT noexcept
#else
#define LUCE_MACRO_NOEXCEPT
#endif

#endif