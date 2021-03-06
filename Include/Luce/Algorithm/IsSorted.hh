#ifndef LUCE_HEADER_ALGORITHM_ISSORTED_HH
#define LUCE_HEADER_ALGORITHM_ISSORTED_HH

#include <cstddef>
#include <vector>

namespace Luce
{
	namespace Algorithm
	{
		template<typename Iterator_>
		bool IsSorted(const Iterator_& begin, const Iterator_& end);
		template<typename Ty_, std::size_t Len_>
		bool IsSorted(const Ty_(&begin)[Len_], const Ty_* const& end);
		template<typename Ty_, std::size_t Len_>
		bool IsSorted(const Ty_(&array)[Len_]);
		template<typename Ty_>
		bool IsSorted(const std::vector<Ty_>& data);
		template<typename Iterator_>
		Iterator_ IsSortedUntil(const Iterator_& begin, const Iterator_& end);
		template<typename Ty_, std::size_t Len_>
		const Ty_* IsSortedUntil(const Ty_(&begin)[Len_], const Ty_* const& end);
		template<typename Ty_, std::size_t Len_>
		const Ty_* IsSortedUntil(const Ty_(&array)[Len_]);
		template<typename Ty_>
		typename std::vector<Ty_>::const_iterator IsSorted(const std::vector<Ty_>& data);
	}

	using Luce::Algorithm::IsSorted;
	using Luce::Algorithm::IsSortedUntil;
}

#include "Detail/IsSorted.hh"
#endif