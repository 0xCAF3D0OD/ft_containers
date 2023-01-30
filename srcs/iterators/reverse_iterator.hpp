//
// Created by Kevin Di nocera on 1/30/23.
//

#ifndef FT_CONTAINERS_REVERSE_ITERATOR_HPP
#define FT_CONTAINERS_REVERSE_ITERATOR_HPP

#include "iterators.hpp"

template <class Iterator>
class reverse_iterator
{
public:
	typedef Iter													iterator_type;
	typedef typename std::iterator_traits<Iter>::iterator_category	iterator_category;
	typedef typename std::iterator_traits<Iter>::value_type			value_type;
	typedef typename std::iterator_traits<Iter>::difference_type	difference_type;
	typedef typename std::iterator_traits<Iter>::pointer			pointer;
	typedef typename std::iterator_traits<Iter>::reference			reference;

protected:
private:
	iterator_type _iterT;
public:
	reverse_iterator(void) : _iterT(0) {}
	/// explicit: prevents implicit conversions. This means that the constructor will not be called when an implicit
	/// conversion is required.

	explicit reverse_iterator (iterator_type it) : _iterT(it) {}

	/// copy constructor: The template allows the reverse iterator to take any type of iterator
	template <class Iter>
	reverse_iterator (const reverse_iterator<Iter> &rev_it){ *this = rev_it; }

	/// assigns another iterator adaptor
	template< class U >
	reverse_iterator &operator=(const reverse_iterator<U> &other)
	{
		if (_iterT != &other)
			_iterT = other._iterT;
		return (*this);
	}

	/// Returns the underlying base(_iterT who is the iterator) iterator.
	iterator_type base() const
	{
		return (_iterT);
	}

	/// Create an attribute tmp in the function and return it.
	reference operator*() const
	{
		Iter tmp = _iterT;
		return *--tmp;
	}

	/// return a reference to the element at relative location.
	/// It returns the element at index "n" (specified as difference_type) starting from the end of
	/// the underlying iterator (base()). The formula used to access the element is "base()[-n-1]" which means
	/// that the element is retrieved starting from the end (base()[-1]) and moving left by n positions (-n).
	reference operator[](difference_type n) const
	{
		return (base()[-n-1])
	}
	
};
#endif //FT_CONTAINERS_REVERSE_ITERATOR_HPP
