//
// Created by Kevin Di nocera on 1/26/23.
//
#include <compare>
#include <iostream>
#include <iterator>
#include <algorithm>

#include "iterators/reverse_iterator.hpp"

int main(void)
{
	int a[] = {0, 1, 2, 3};
	//            ↑  └───── x, y
	//            └──────── z

	std::reverse_iterator<int*>
			x = {std::rend(a) - std::size(a)},
			y = {std::rend(a) - std::size(a)},
			z = {std::rbegin(a) + 1};

	std::cout
			<< std::boolalpha
			<< "*x == " << *x << '\n' // 3
			<< "*y == " << *y << '\n' // 3
			<< "*z == " << *z << '\n' // 2
			<< "x == y ? " << (x == y) << '\n' // true
			<< "x != y ? " << (x != y) << '\n' // false
			<< "x <  y ? " << (x <  y) << '\n' // false
			<< "x <= y ? " << (x <= y) << '\n' // true
			<< "x == z ? " << (x == z) << '\n' // false
			<< "x != z ? " << (x != z) << '\n' // true
			<< "x <  z ? " << (x <  z) << '\n' // true
			<< "x <= z ? " << (x <= z) << '\n' // true
			<< std::endl;

}