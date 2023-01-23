//
// Created by Kevin Di nocera on 1/19/23.
//

#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP

namespace ft
template < class T, class allocator = std::allocator<T> >
class vector
{
public:
	typedef typename value_type 						T;
	typedef typename allocator 							Alloc;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef implementation-defined						iterator;
	typedef implementation-defined						const_iterator;
	typedef typename allocator_type::size_type			size_type;
	typedef typename allocator_type::difference_type	difference_type;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;
	typedef std::reverse_iterator<iterator>				reverse_iterator;
	typedef std::reverse_iterator<const_iterator>		const_reverse_iterator;

private:
};

#endif //FT_CONTAINERS_VECTOR_HPP
