//
// Created by dino on 01.02.23.
//

#ifndef FT_CONTAINERS_RANDOM_ACCESS_ITERATOR_HPP
#define FT_CONTAINERS_RANDOM_ACCESS_ITERATOR_HPP

#include "iterator_trait.hpp"
namespace ft
{
	///std::iterator_traits is the type trait class that provides uniform interface to the properties of LegacyIterator
	/// types. This makes it possible to implement algorithms only in terms of iterators.

	///Iterator - the iterator type to retrieve properties for.
	template <class Iter>
	class iterator_traits
	{
		//The iterator category. It can be one of these:
		// 1. input_iterator_tag,
		// 2. output_iterator_tag,
		// 3. forward_iterator_tag,
		// 4. bidirectional_iterator_tag,
		// 5. random_access_iterator_tag.
		typedef typename Iter::iterator_category	iterator_category;

		//Type to express the result of subtracting one iterator from another.
		typedef typename Iter::difference_type		difference_type;

		//The type of the element the iterator can point to.
		typedef typename Iter::value_type			value_type;

		//The type of pointer to an element the iterator can point to.
		typedef typename Iter::pointer				pointer;

		//The type of reference to an element the iterator can point to.
		typedef typename Iter::reference			reference;
	};
	///specializations determine the critical types associated with an object pointer of type Type* or const Type*.
	template <class T>
	class iterator_traits<T*>
	{
		typedef typename std::random_access_iterator_tag	iterator_category;
		typedef typename std::ptrdiff_t						difference_type;
		typedef T											value_type;
		typedef T*											pointer;
		typedef T&											reference;
	};

	template <class T>
	class iterator_traits<const T*>
	{
		typedef typename std::random_access_iterator_tag	iterator_category;
		typedef typename std::ptrdiff_t						difference_type;
		typedef T											value_type;
		typedef const T*									pointer;
		typedef const T&									reference;
	};

/*
* Random-access iterators allow to access elements at an
* arbitrary offset position relative to the element they point
* to. This is the most complete iterators. All pointer types
* are also valid random-access-iterators.
*/
	template<class Iter>
	class random_access_iterator
	{
	public:
		typedef Iter															iterator_type;
		typedef typename ft::iterator_traits<iterator_type>::value_type			value_type;
		typedef typename ft::iterator_traits<iterator_type>::pointer			pointer;
		typedef typename ft::iterator_traits<iterator_type>::reference			reference;
		typedef typename ft::iterator_traits<iterator_type>::difference_type	difference_type;
		typedef typename ft::iterator_traits<iterator_type>::iterator_category	iterator_category;
	protected:
		pointer _ptr;
	public:

		//Default constructor
		random_access_iterator(void) : _ptr(nullptr) {}
		random_access_iterator(pointer rhs) : _ptr(rhs) {}

		//Copy constructor
		template< class type >
		random_access_iterator(const random_access_iterator<type> &srcs) : _ptr(NULL) {
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
		pointer base(void) const {
			return (this->_ptr);
		}

		// Give the lvalue of the element where is the random_access_iterator.
		// Return the lvalue (the pointer to the element).
		pointer operator->(void) {
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
	};
}
#endif //FT_CONTAINERS_RANDOM_ACCESS_ITERATOR_HPP
