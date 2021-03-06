#ifndef LUCE_HEADER_TEXT_STRING_HH
#define LUCE_HEADER_TEXT_STRING_HH
#include <Luce/Configuration.hh>

namespace Luce
{
	namespace Text
	{
		class LUCE_MACRO_EXPORT String LUCE_MACRO_FINAL
		{
			LUCE_MACRO_CANNOT_PARENT(String)

		public:
			
		};
	}

	using Luce::Text::String;
}

#if !defined(LUCE_MACRO_LINKING_TEXT) && LUCE_MACRO_IS_MSVC
#define LUCE_MACRO_LINKING_TEXT
#pragma comment(lib, "Luce-Text.lib")
#endif
#endif