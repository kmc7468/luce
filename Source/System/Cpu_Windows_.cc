#include <Luce/System/Cpu.hh>

#if LUCE_MACRO_IS_WINDOWS
#include <Luce/Exception/LuceException.hh>
#include <Luce/Exception/NotSupportedPlatform.hh>
#include <Luce/Exception/UncaughtApiError.hh>
#include <Luce/Utility/Integer.hh>

#include <cstddef>
#include <cstdlib>
#include <new>
#include <Windows.h>

namespace Luce
{
	namespace System
	{
		std::vector<Cpu> Cpu::GetCpus()
		{
			BOOL(WINAPI* glpi)(PSYSTEM_LOGICAL_PROCESSOR_INFORMATION, PDWORD);
			PSYSTEM_LOGICAL_PROCESSOR_INFORMATION buf = NULL;

			glpi = reinterpret_cast<
				BOOL(WINAPI*)(PSYSTEM_LOGICAL_PROCESSOR_INFORMATION, PDWORD)>(
				GetProcAddress(
					GetModuleHandle(TEXT("kernel32")), "GetLogicalProcessorInformation"));

			if (glpi == NULL)
			{
				throw Exception::NotSupportedPlatform(__LINE__, __FILE__, __FUNCTION__);
			}

			std::vector<Cpu> cpus;
			DWORD retlen = 0;

			BOOL done = FALSE;
			while (!done)
			{
				DWORD rc = glpi(buf, &retlen);

				if (rc == FALSE)
				{
					if (GetLastError() == ERROR_INSUFFICIENT_BUFFER)
					{
						if (buf)
						{
							std::free(buf);
						}

						buf = reinterpret_cast<PSYSTEM_LOGICAL_PROCESSOR_INFORMATION>(
							std::malloc(retlen));

						if (buf == NULL)
						{
							throw Exception::LuceException(
								std::bad_alloc(), __LINE__ - 1, __FILE__, __FUNCTION__);
						}
					}
					else
					{
						if (buf)
						{
							std::free(buf);
						}

						throw Exception::UncaughtApiError(__LINE__, __FILE__, __FUNCTION__);
					}
				}
				else
				{
					done = TRUE;
				}
			}

			DWORD byte_offset = 0;

			Utility::UIntMax cpu_count = 0;
			Utility::UIntMax core_count = 0;

			while (byte_offset + sizeof(SYSTEM_LOGICAL_PROCESSOR_INFORMATION) <= retlen)
			{
				switch (buf->Relationship)
				{
				case RelationProcessorCore:
					++core_count;
					break;

				case RelationProcessorPackage:
					++cpu_count;
					break;

				default:
					break;
				}

				byte_offset += sizeof(SYSTEM_LOGICAL_PROCESSOR_INFORMATION);
				++buf;
			}

			if (buf)
			{
				std::free(buf);
			}

			

			return cpus;
		}
	}
}
#endif