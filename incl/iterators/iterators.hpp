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

/*
 * Iterator traits in C++ vector containers allow you to define iterators
 * to traverse the elements of a vector sequentially.
 * */
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


	//iterator_traits is the type trait class that provides uniform interface to the properties of LegacyIterator
	// types. This makes it possible to implement algorithms only in terms of iterators.

	///Iterator - the iterator type to retrieve properties for.
	template <class Iterator>
		struct iterator_traits
		{
			//The iterator category. It can be one of these:
			// 1. input_iterator_tag,
			// 2. output_iterator_tag,
			// 3. forward_iterator_tag,
			// 4. bidirectional_iterator_tag,
			// 5. random_access_iterator_tag.
			typedef typename Iterator::iterator_category	iterator_category;

			//Type to express the result of subtracting one iterator from another.
			typedef typename Iterator::difference_type		difference_type;

			//The type of the element the iterator can point to.
			typedef typename Iterator::value_type			value_type;

			//The type of pointer to an element the iterator can point to.
			typedef typename Iterator::pointer				pointer;

			//The type of reference to an element the iterator can point to.
			typedef typename Iterator::reference			reference;
		};
	///specializations determine the critical types associated with an object pointer of type Type* or const Type*.
	template <class T>
		class iterator_traits<T*>
		{
			typedef random_access_iterator_tag	iterator_category;
			typedef ptrdiff_t					difference_type;
			typedef T							value_type;
			typedef T*							pointer;
			typedef T&							reference;
		};

		template <class T>
		class iterator_traits<const T*>
		{
			typedef random_access_iterator_tag	iterator_category;
			typedef ptrdiff_t					difference_type;
			typedef T							value_type;
			typedef const T*					pointer;
			typedef const T&					reference;
		};
}

#endif //FT_CONTAINERS_ITERATORS_HPP
