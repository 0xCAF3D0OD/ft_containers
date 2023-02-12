//
// Created by Kevin Di nocera on 2/6/23.
//

#ifndef FT_CONTAINERS_UTILS_HPP
#define FT_CONTAINERS_UTILS_HPP

#include <cstddef>
#include <tuple>
#include <memory>
#include <cstddef>
#include <iostream>
#include <stdexcept>

#include "iterators/iterators.hpp"
#include "iterators/reverse_iterator.hpp"
#include "iterators/random_access_iterator.hpp"

namespace ft
{
	template < class ForwardIterator, class Size, class T, class pointer>
	void uninitialized_fill_n_ptr (pointer first, Size n, const T &value)
	{
		for (; n--; ++first)
			new (static_cast<void*>(&*first))
					typename iterator_traits<ForwardIterator>::value_type(value);
	}

	template< class InputIt >
	typename ft::iterator_traits<InputIt>::difference_type
	distance(InputIt first, InputIt last) {
		return (last - first);
	}
}
#endif //FT_CONTAINERS_UTILS_HPP
