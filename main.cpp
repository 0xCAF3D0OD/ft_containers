//
// Created by Kevin Di nocera on 1/26/23.
//
#include <compare>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>
#include <typeinfo>

#include "incl/vector.hpp"
#include "incl/iterators/iterators.hpp"
// inserting into a vector
#include <vector>

//using namespace std;
using namespace ft;

// reverse_iterator example

int main () {
	vector<int> my_vector;
	for (int i=0; i<10; i++) myvector.push_back(i);

	typedef vector<int>::iterator iter_type;
	// ? 9 8 7 6 5 4 3 2 1 0 ?
	iter_type from (my_vector.begin());                     //   ^
	//         ------>
	iter_type until (my_vector.end());                      //                       ^
	//
	reverse_iterator<iter_type> rev_until (from);     // ^
	//         <------
	reverse_iterator<iter_type> rev_from (until);     //                     ^

	std::cout << "my_vector:";
	while (rev_from != rev_until) {
		std::cout << ' ' << *rev_from;
		++rev_from;
	}
	std::cout << '\n';

	return 0;
}
