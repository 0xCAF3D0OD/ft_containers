//
// Created by Kevin Di nocera on 1/27/23.
//

#ifndef FT_CONTAINERS_ITERATORS_HPP
#define FT_CONTAINERS_ITERATORS_HPP

/*Iterator traits in C++ vector containers allow you to define iterators
 * to traverse the elements of a vector sequentially.*/
namespace ft
{
	//iterator
	template <class Category, class T, class Distance = ptrdiff_t,class Pointer = T*, class Reference = T&>
	struct iterator
	{
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
		typedef Category  iterator_category;
	};

	//iterator traits
	template <class Iterator>
	struct iterator_traits
	{
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
		typedef Category  iterator_category;
	};

	template <class T>
	struct iterator_traits<T*>
	{
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
		typedef Category  iterator_category;
	};

	template <class T>
	struct iterator_traits<const T*>
	{
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
		typedef Category  iterator_category;
	};

	//iterator tag
	struct input_iterator_tag {};

	struct output_iterator_tag {};

	struct forward_iterator_tag {};

	struct bidirectional_iterator_tag {};

	struct random_access_iterator_tag    : public bidirectional_iterator_tag
	{

	};

	template <class T>
	struct is_default_constructible
	{

	};

	template <class T>
	struct is_copy_constructible
	{

	};

	template <class T>
	struct is_copy_assignable
	{

	};
};

#endif //FT_CONTAINERS_ITERATORS_HPP
