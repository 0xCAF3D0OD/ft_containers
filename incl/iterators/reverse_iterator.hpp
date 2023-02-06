//
// Created by Kevin Di nocera on 1/30/23.
//

#ifndef FT_CONTAINERS_REVERSE_ITERATOR_HPP
#define FT_CONTAINERS_REVERSE_ITERATOR_HPP

#pragma once

#include <tuple>
#include <memory>
#include <cstddef>
#include <iostream>
#include <stdexcept>

#include "../utils.hpp"
#include "iterators.hpp"
#include "iterator_trait.hpp"
#include "random_access_iterator.hpp"

/*
 * std::reverse_iterator is an iterator adaptor that reverses the direction of a given iterator
 * when provided with a bidirectional iterator, std::reverse_iterator produces a new iterator that moves from the end
 * to the beginning of the sequence defined by the underlying bidirectional iterator.
 * */
namespace ft
{
	template <class Iter>
	class reverse_iterator
	{
	public:
		typedef Iter													iterator_type;
		typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<Iter>::value_type			value_type;
		typedef typename ft::iterator_traits<Iter>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iter>::pointer				pointer;
		typedef typename ft::iterator_traits<Iter>::reference			reference;

		// ? pourquoi un iterator type pour le reverse et un pointeur pour le random_access
	private:
		iterator_type _iterT;
	public:
		reverse_iterator(void) : _iterT(0) {}

		/// explicit: prevents implicit conversions. This means that the constructor will not be called when an implicit
		/// conversion is required.
		explicit reverse_iterator (iterator_type it) : _iterT(it) {}

		/// copy constructor: The template allows the reverse iterator to take any type of iterator
		template <class Iterator>
		reverse_iterator (const reverse_iterator<Iterator> &rev_it){ *this = rev_it.base(); }

		//destructor
		~reverse_iterator();

		/// assigns another iterator adaptor
		template< class U >
		reverse_iterator &operator=(const reverse_iterator<U> &other)
		{
			if (this != &other)
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

		///Operator++ decrement the table as it is the reverse iterator
		reverse_iterator& operator++(void)
		{
			this->_iterT--;
			return (*this);
		}

		///the same logic with the operator--
		reverse_iterator& operator--(void)
		{
			this->_iterT++;
			return (*this);
		}

		/// Post-increments or post-decrements by one respectively.
		reverse_iterator operator++(int)
		{
			reverse_iterator bfr = *_iterT;
			this->_iterT--;
			return (bfr);
		}

		/// Post-increments or post-decrements by one respectively.
		reverse_iterator operator--(int)
		{
			reverse_iterator bfr = *_iterT;
			this->_iterT++;
			return (bfr);
		}

		///Returns an iterator which is advanced by n or -n positions respectively.
		reverse_iterator operator+(difference_type n) const {
			return (reverse_iterator(base()-n));
		}

		///Returns an iterator which is advanced by n or -n positions respectively.
		reverse_iterator operator-(difference_type n) const {
			return (reverse_iterator(base()+n));
		}

		///Advances the iterator by n or -n positions respectively.
		reverse_iterator& operator+=(difference_type n)
		{
			this->_iterT -= n;
			return (*this);
		}

		///Advances the iterator by n or -n positions respectively.
		reverse_iterator& operator-=(difference_type n)
		{
			this->_iterT += n;
			return (*this);
		}

		// The purpose of the friend kewword is for make the access to the data easier.
		// `friend` let you use the variable lhs and rhs in one time, and not two like the conventional way with a template.
		friend bool operator==(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs) {
			return (lhs.base() == rhs.base());
		}

		friend bool operator!=(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs) {
			return (lhs.base() != rhs.base());
		}

		friend bool operator<(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs) {
			return (lhs.base() < rhs.base());
		}

		friend bool operator<=(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs) {
			return (lhs.base() <= rhs.base());
		}

		friend bool operator>(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs) {
			return (lhs.base() > rhs.base());
		}

		friend bool operator>=(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs) {
			return (lhs.base() >= rhs.base());
		}
	};
}
#endif //FT_CONTAINERS_REVERSE_ITERATOR_HPP
