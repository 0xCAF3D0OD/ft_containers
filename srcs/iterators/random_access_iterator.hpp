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
		Type *_ptr;
	public:
		random_access_iterator(void) : _ptr(nullptr) {}
		random_access_iterator(Type *rhs) : _ptr(rhs) {}
		random_access_iterator(const Iterator &rhs) : _ptr(rhs._ptr) {}

		template< class U >
		random_access_iterator &operator=(const random_access_iterator<U> &other)
		{
			if (_iterT != &other)
				_iterT = other._iterT;
			return (*this);
		}

		/// Returns the underlying base(_iterT who is the iterator) iterator.
		iterator_type base(void) const
		{
			return (_iterT);
		}

		/// Create an attribute tmp in the function and return it.
		reference operator*(void) const
		{
			Iter tmp = _iterT;
			return (*--tmp);
		}

		/// return a reference to the element at relative location.
		/// It returns the element at index "n" (specified as difference_type) starting from the end of
		/// the underlying iterator (base()). The formula used to access the element is "base()[-n-1]" which means
		/// that the element is retrieved starting from the end (base()[-1]) and moving left by n positions (-n).
		reference operator[](difference_type n) const
		{
			return (base()[-n-1]);
		}

		random_access_iterator& operator++(void)
		{
			this->_iterT++;
			return (*this);
		}

		random_access_iterator& operator--(void)
		{
			this->_iterT--;
			return (*this);
		}

		/// Post-increments or post-decrements by one respectively.
		random_access_iterator operator++(int)
		{
			random_access_iterator bfr = *_iterT;
			this->_iterT++;
			return (bfr);
		}

		/// Post-increments or post-decrements by one respectively.
		random_access_iterator operator--(int)
		{
			random_access_iterator bfr = *_iterT;
			this->_iterT--;
			return (bfr);
		}

		///Returns an iterator which is advanced by n or -n positions respectively.
		random_access_iterator operator+(difference_type n) const {
			return (random_access_iterator(base()+n));
		}

		///Returns an iterator which is advanced by n or -n positions respectively.
		random_access_iterator operator-(difference_type n) const {
			return (random_access_iterator(base()-n));
		}

		///Advances the iterator by n or -n positions respectively.
		random_access_iterator& operator+=(difference_type n)
		{
			this->_iterT += n;
			return (*this);
		}

		///Advances the iterator by n or -n positions respectively.
		random_access_iterator& operator-=(difference_type n)
		{
			this->_iterT -= n;
			return (*this);
		}
	}
}
#endif //FT_CONTAINERS_RANDOM_ACCESS_ITERATOR_HPP
