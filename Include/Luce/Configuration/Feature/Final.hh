#ifndef LUCE_HEADER_CONFIGURATION_FEATURE_FINAL_HH
#define LUCE_HEADER_CONFIGURATION_FEATURE_FINAL_HH
#include <Luce/Configuration/Basic-Value.hh>

#if LUCE_MACRO_IS_YES(LUCE_CONFIG_FINAL) 
#define LUCE_MACRO_FINAL final
#else
#define LUCE_MACRO_FINAL
#endif

#endif