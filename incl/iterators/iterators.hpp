//
// Created by Kevin Di nocera on 1/27/23.
//

#ifndef FT_CONTAINERS_ITERATORS_HPP
#define FT_CONTAINERS_ITERATORS_HPP

#include <cstddef>
#include <tuple>
#include <memory>
#include <cstddef>
#include <iostream>
#include <stdexcept>

#pragma once

#include "../utils.hpp"
#include "iterator_trait.hpp"
#include "reverse_iterator.hpp"
#include "random_access_iterator.hpp"

/*Iterator traits in C++ vector containers allow you to define iterators
 * to traverse the elements of a vector sequentially.*/
namespace ft
{
	//iterator
	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator
	{
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
		typedef Category  iterator_category;
	};

	//iterator tag
	///Marking intput iterators.
	struct input_iterator_tag {};

	///Marking output iterators.
	struct output_iterator_tag {};

	/// Forward iterators support a superset of input iterator operations.
	struct forward_iterator_tag : public output_iterator_tag {};

	/// Bidirectional iterators support a superset of forward iterator operations.
	struct bidirectional_iterator_tag : public  forward_iterator_tag {};

	/// Random-access iterators support a superset of bidirectional iterators operations
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};
//
//	template <class T>
//	struct is_default_constructible
//	{};
//
//	template <class T>
//	struct is_copy_constructible
//	{};
//
//	template <class T>
//	struct is_copy_assignable
//	{};

};

#endif //FT_CONTAINERS_ITERATORS_HPP
