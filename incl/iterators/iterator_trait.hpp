//
// Created by dino on 01.02.23.
//

#ifndef FT_CONTAINERS_ITERATOR_TRAIT_HPP
#define FT_CONTAINERS_ITERATOR_TRAIT_HPP

#include <cstddef>
#include <tuple>
#include <memory>
#include <cstddef>
#include <iostream>
#include <stdexcept>

#include "../utils.hpp"
#include "iterators.hpp"
#include "reverse_iterator.hpp"
#include "random_access_iterator.hpp"

namespace ft
{
	///std::iterator_traits is the type trait class that provides uniform interface to the properties of LegacyIterator
	/// types. This makes it possible to implement algorithms only in terms of iterators.

	///Iterator - the iterator type to retrieve properties for.
	template <class Iter>
	class iterator_traits
	{
		//The iterator category. It can be one of these:
		// 1. input_iterator_tag,
		// 2. output_iterator_tag,
		// 3. forward_iterator_tag,
		// 4. bidirectional_iterator_tag,
		// 5. random_access_iterator_tag.
		typedef typename Iter::iterator_category	iterator_category;

		//Type to express the result of subtracting one iterator from another.
		typedef typename Iter::difference_type		difference_type;

		//The type of the element the iterator can point to.
		typedef typename Iter::value_type			value_type;

		//The type of pointer to an element the iterator can point to.
		typedef typename Iter::pointer				pointer;

		//The type of reference to an element the iterator can point to.
		typedef typename Iter::reference			reference;
	};
	///specializations determine the critical types associated with an object pointer of type Type* or const Type*.
	template <class T>
	class iterator_traits<T*>
	{
		typedef typename std::random_access_iterator_tag	iterator_category;
		typedef typename std::ptrdiff_t						difference_type;
		typedef T											value_type;
		typedef T*											pointer;
		typedef T&											reference;
	};

	template <class T>
	class iterator_traits<const T*>
	{
		typedef typename std::random_access_iterator_tag	iterator_category;
		typedef typename std::ptrdiff_t						difference_type;
		typedef T											value_type;
		typedef const T*									pointer;
		typedef const T&									reference;
	};
}
#endif //FT_CONTAINERS_ITERATOR_TRAIT_HPP
