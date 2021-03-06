#ifndef LUCE_HEADER_CONFIGURATION_PLATFORM_VALUE_HH
#define LUCE_HEADER_CONFIGURATION_PLATFORM_VALUE_HH

#define LUCE_CONFIG_WINDOWS (1985114L)
#define LUCE_CONFIG_LINUX (1991094L)
#define LUCE_CONFIG_UNIX (1973104L)

#define LUCE_MACRO_IS_WINDOWS (LUCE_CONFIG_PLATFORM == LUCE_CONFIG_WINDOWS)
#define LUCE_MACRO_IS_LINUX (LUCE_CONFIG_PLATFORM == LUCE_CONFIG_LINUX)
#define LUCE_MACRO_IS_UNIX (LUCE_CONFIG_PLATFORM == LUCE_CONFIG_UNIX)

#endif