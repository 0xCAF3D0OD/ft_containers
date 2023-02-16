//
// Created by Kevin Di nocera on 1/26/23.
//
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

#include "incl/vector.hpp"
#include "incl/iterators/iterators.hpp"

using namespace ft;
// reverse_iterator example

#include <iostream>
//#include <iterator>
//#include <list>
//#include <vector>

int main()
{
	// Create a vector containing integers
	vector<int> v (7, 5, 16, 8);

	// Add two more integers to vector
	v.push_back(25);
	v.push_back(13);
	// Print out the vector
	std::cout << "v = { ";
	for (size_t n = 0; n < v.size(); ++n)
		std::cout << n << ", ";
	std::cout << "}; \n";
	return (0);
}