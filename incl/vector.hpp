//
// Created by Kevin Di nocera on 1/19/23.
//

#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP

#include <cstddef>
#include <tuple>
#include <memory>
#include <cstddef>
#include <iostream>
#include <stdexcept>

#include "utils.hpp"
#include "iterators/iterators.hpp"
#include "iterators/reverse_iterator.hpp"
#include "iterators/random_access_iterator.hpp"

namespace ft
{
/*
 * A namespace is a declarative region that provides a scope to the identifiers (the names of types, functions,
 * variables, etc) inside it
 */
	template<class T, class allocator = std::allocator<T> >
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

		vector(void) : _alloc(0), _container(NULL), _size(0), _capacity(0) {}

		/* Default constructor initialize all attribute*/
		explicit vector(const allocator_type& alloc = allocator_type())
		: _alloc(alloc), _container(NULL), _size(0), _capacity(0) {}

		//fill constructor
		/* std::uninitialized_fill_n allows you to fill a memory area with values using a copy constructor.
		 * It takes three arguments.
		 * * A pointer to the beginning of the memory area to be filled -> attribute _container.
		 * * The number of elements to fill (of type size_t) -> variable n.
		 * * A reference to the object to be copied to fill the memory area -> variable val.
		 * This function is useful when you want to fill a memory area with objects that have a copy constructor defined,
		 * but without initializing these objects explicitly.
		 * It is more efficient than using a loop to create objects and copy them one by one.
		 */
		explicit vector(size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type())
		: _alloc(alloc), _container(NULL), _size(n), _capacity(n)
		{
			if (this->_capacity > this->max_size())
				throw (std::length_error("cannot create ft::vector larger than max_size()"));
			this->_container = _alloc.allocate(this->_capacity);
//			ft::uninitialized_fill_n_ptr(this->_container, n, val);
			for (size_type i = 0; i != n; i++)
				this->_alloc.construct(this->_container[i], val);
		}

		// range constructor
		// creates vector with the range between it_start and it_end and copies the corresponding values
		template <class InputIterator>
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
		: _alloc(alloc), _container(NULL), _size(0), _capacity(0)
		{
			// calculate the size.
			for (InputIterator tmp = first; tmp != last; ++tmp)
				this->_size++;
			this->_capacity = this->_size;
			this->_container = this->_alloc.allocate(this->_capacity);
			for (size_type i = 0; i != this->_capacity; i++)
			{
				this->_alloc.construct(this->_container[i], &(first));
				++first;
			}
			// fill the range from first to the end.
//			std::uninitialized_fill_n(first, this->_capacity, this->_container);
		}

		// copy constructor
		vector (const vector& srcs)
		: _container(NULL), _size(0), _capacity(0) {
			*this = srcs;
		}

		vector& operator=(const vector& other)
		{
			this->_container = other._container;
			this->_capacity = other._capacity;
			this->_alloc = other._alloc;
			this->_size = other._size;
			return (*this);
		}
		//Replaces the contents with count copies of value.
		void assign(size_type count, const T& value)
		{
			if (this->_capacity)
			{
				this->_container = this->_alloc.allocate(this->_capacity);
				for (size_type i = 0; i != count; ++i)
					this->_container[i] = value;
			}
		}

		allocator_type get_allocator() const {
			return (this->_alloc);
		}

		///ELEMENT ACCESS
		//Returns a reference to the element at specified location pos, with bounds checking.
		//If pos is not within the range of the container, an exception of type std::out_of_range is thrown.
		reference at(size_type pos)
		{
			if (pos >= this->_size)
				throw std::out_of_range("out of range exception");
			return (this->_container[pos]);
		}

		const_reference at (size_type pos) const
		{
			if (pos >= this->_size)
				throw std::out_of_range("out of range exception");
			return (this->_container[pos]);
		}

		reference operator[](size_type pos) {
			return (this->_container[pos]);
		}

		const_reference operator[](size_type pos) const {
			return (this->_container[pos]);
		}

		// Returns a reference to the first element in the container.
		// If the return value contain '[]' no need of '*'. But if it doesn't contain '[]' the '*' is needed.
		reference front(void) {
			return (*(this->_container));
		}

		const_reference front(void) const {
			return (*(this->_container));
		}

		// Returns a reference to the last element in the container.
		reference back(void) {
			return (this->_container[this->_size]);
		}

		const_reference back(void) const {
			return (this->_container[this->_size]);
		}

		T* data(void) {
			return (this->_container);
		}

		const T* data(void) const {
			return (this->_container);
		}

		iterator begin(void) {
			return (iterator(this->_container));
		}

		///ITERATOR
		const_iterator begin(void) const {
			return (const_iterator(this->_container));
		}

		iterator end(void)
		{
			if (!this->_container)
				return (iterator(this->_container));
			return(iterator(this->_container[this->_size]));
		}

		const_iterator end(void) const
		{
			if (!this->_container)
				return (iterator(this->_container));
			return(const_iterator(this->_container[this->_size]));
		}

		///CAPACITY
		// Checks if the container has no elements.
		bool empty(void) const {
			if (begin() == end())
				return (true);
			return (false);
		}

		// Returns the number of elements in the container.
		size_type size(void) const {
			return (ft::distance(begin(), end()));
		}

		size_type max_size() const {
			return (ft::distance(begin(), end()));
		}

		size_type capacity() const {
			return (this->_capacity);
		}

		//Increase the capacity of the vector (the total number of elements that the vector can hold without requiring
		//reallocation) to a value that's greater or equal to new_cap. If new_cap is greater than the current capacity(), new storage is allocated, otherwise the function does nothing.
		void reserve(size_type new_cap)
		{
			if (new_cap > max_size())
				std::length_error("reserve exception\n");
			else if (n <= this->_capacity)
				return ;
			if (new_cap > this->_capacity)
				this->_container = this->_alloc.allocate(new_cap);
		}

		~vector() {
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
