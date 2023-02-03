//
// Created by dino on 01.02.23.
//

#ifndef FT_CONTAINERS_RANDOM_ACCESS_ITERATOR_HPP
#define FT_CONTAINERS_RANDOM_ACCESS_ITERATOR_HPP

#include "iterators.hpp"
#include "iterator_trait.hpp"

/*
* Random-access iterators allow to access elements at an
* arbitrary offset position relative to the element they point
* to. This is the most complete iterators. All pointer types
* are also valid random-access-iterators.
*/

namespace ft
{
	template<Type>
	class random_access_iterator : public ft::iterator<random_access_iterator_tag, Type>
	{
	protected:
		Pointer _ptr;
	public:

		//Default constructor
		random_access_iterator(void) : _ptr(nullptr) {}
		random_access_iterator(Pointer rhs) : _ptr(rhs) {}

		//Copy constructor
		template< class type >
		random_access_iterator(const random_access_iterator<type> &src) : _ptr(NULL) {
			*this = srcs;
		}

		// destructor
		~random_access_iterator();

		// Operator "="
		template< class U >
		random_access_iterator &operator=(const random_access_iterator<U> &other)
		{
			if (this != &other)
				_ptr = other._ptr;
			return (*this);
		}

		// Returns the underlying base(_ptr who is the iterator) iterator.
		Pointer base(void) const {
			return (this->_ptr);
		}

		// Give the lvalue of the element where is the random_access_iterator.
		// Return the lvalue (the pointer to the element).
		Pointer operator->(void) {
			return &(this->operator*());
		}

		// Create an attribute tmp in the function and return it.
		reference operator*(void) const {
			return (*(this->_ptr));
		}

		/// return a reference to the element at relative location.
		/// It returns the element at index "n" (specified as difference_type) starting from the end of
		/// the underlying iterator (base()). The formula used to access the element is "base()[-n-1]" which means
		/// that the element is retrieved starting from the end (base()[-1]) and moving left by n positions (-n).
		reference operator[](difference_type n) const {
			return (*(this->_ptr + n));
		}

		// convert normal type to const type
		operator random_access_iterator<const T>() const {
			return (random_access_iterator<const T>(this->_ptr));
		}

		random_access_iterator &operator++(void) {
			return (this->_ptr++);
		}

		random_access_iterator &operator--(void) {
			return (this->_ptr--);
		}

		// Post-increments or post-decrements by one respectively.
		random_access_iterator operator++(int)
		{
			random_access_iterator bfr = *_ptr;
			this->_ptr++;
			return (bfr);
		}

		//Pourquoi trois fois le meme operateur
		const random_access_iterator operator+(size_t index) const {
			return (this->_ptr + index);
		}

		friend difference_type operator+(const random_access_iterator &lhs, const random_access_iterator &rhs) {
			return (lhs._ptr + rhs._ptr);
		}

		// Post-increments or post-decrements by one respectively.
		random_access_iterator operator--(int)
		{
			random_access_iterator bfr = *_ptr;
			this->_ptr--;
			return (bfr);
		}

		//Pourquoi trois fois le meme operateur
		const random_access_iterator operator-(size_t index) const {
			return (this->_ptr - index);
		}

		friend difference_type operator-(const random_access_iterator &lhs, const random_access_iterator &rhs) {
			return (lhs._ptr - rhs._ptr);
		}

		// Returns an iterator which is advanced by n or -n positions respectively.
		random_access_iterator operator+(difference_type n) const {
			return (random_access_iterator(base() + n));
		}

		// Returns an iterator which is advanced by n or -n positions respectively.
		random_access_iterator operator-(difference_type n) const {
			return (random_access_iterator(base() - n));
		}

		// Advances the iterator by n or -n positions respectively.
		random_access_iterator& operator+=(difference_type n)
		{
			this->_ptr += n;
			return (*this);
		}

		// Advances the iterator by n or -n positions respectively.
		random_access_iterator& operator-=(difference_type n)
		{
			this->_ptr -= n;
			return (*this);
		}

		// COMPARE OPERATORS
		friend bool operator==(const random_access_iterator<Type> &lhs, const random_access_iterator<Type> &rhs) {
			return (lhs.base() == rhs.base());
		}

		friend bool operator!=(const random_access_iterator<Type> &lhs, const random_access_iterator<Type> &rhs) {
			return (lhs.base() != rhs.base());
		}

		friend bool operator<(const random_access_iterator<Type> &lhs, const random_access_iterator<Type> &rhs) {
			return (lhs.base() < rhs.base());
		}

		friend bool operator<=(const random_access_iterator<Type> &lhs, const random_access_iterator<Type> &rhs) {
			return (lhs.base() <= rhs.base());
		}

		friend bool operator>(const random_access_iterator<Type> &lhs, const random_access_iterator<Type> &rhs) {
			return (lhs.base() > rhs.base());
		}

		friend bool operator>=(const random_access_iterator<Type> &lhs, const random_access_iterator<Type> &rhs) {
			return (lhs.base() >= rhs.base());
		}
	}
}
#endif //FT_CONTAINERS_RANDOM_ACCESS_ITERATOR_HPP
