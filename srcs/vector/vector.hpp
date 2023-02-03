//
// Created by Kevin Di nocera on 1/19/23.
//

#include <vector>
#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP

#include <iostream>
#include <memory>
#include <cstddef>
#include <stdexcept>
#include <tuple>
#include "../iterators/iterators.hpp"
#include "../iterators/iterator_trait.hpp"
#include "../iterators/reverse_terator.hpp"
#include "../iterators/random_access_iterator.hpp"

namespace ft
{
/*
 * A namespace is a declarative region that provides a scope to the identifiers (the names of types, functions,
 * variables, etc) inside it
 */
	template<class T, class allocator = std::allocator <T> >
	class vector {
	public:
		typedef T 												value_type;
		typedef allocator 										allocator_type;
		typedef typename allocator_type::reference 				reference;
		typedef typename allocator_type::const_reference 		const_reference;
		typedef typename allocator_type::size_type 				size_type;
		typedef typename allocator_type::difference_type 		difference_type;
		typedef typename allocator_type::pointer 				pointer;
		typedef typename allocator_type::const_pointer 			const_pointer;
		typedef ft::random_access_iterator<value_type>			iterator;
		typedef ft::random_access_iterator<const value_type>	const_iterator;
		typedef ft::reverse_iterator<iterator>					reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;

		vector(void) : _alloc(0), _container(NULL), _size(0), _capacity(0);

		/* Default constructor initialize all attribute*/
		explicit vector(const allocator_type &alloc = allocator_type())
				: _alloc(alloc), _container(NULL), _size(0), _capacity(0) {}

		/* std::uninitialized_fill_n allows you to fill a memory area with values using a copy constructor.
		 * It takes three arguments.
		 * * A pointer to the beginning of the memory area to be filled -> attribute _container.
		 * * The number of elements to fill (of type size_t) -> variable n.
		 * * A reference to the object to be copied to fill the memory area -> variable val.
		 * This function is useful when you want to fill a memory area with objects that have a copy constructor defined,
		 * but without initializing these objects explicitly.
		 * It is more efficient than using a loop to create objects and copy them one by one.
		 */
		explicit vector(size_type n, const value_type &val = value_type(),
						const allocator_type &alloc = allocator_type())
				: _alloc(alloc), _container(NULL), _size(0), _capacity(0) {
			_container = _alloc.allocate(n);
			std::uninitialized_fill_n(_container, n, val);
			_size = n;
			_capacity = n;
			std::cout << _size << " " << _capacity << std::endl;
		}

		template <class InputIterator>
		vector (InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type())
		{
			if (value_type)
		}

		iterator begin() {return (iterator(_container));}
		const_iterator begin() {return (const_iterator(_container));}

		~vector()
		{
			delete [] _container;
		}

	private:
		allocator_type	_alloc;
		pointer 		_container;
		size_type		_size;
		size_type		_capacity;


	};
}
#endif //FT_CONTAINERS_VECTOR_HPP
