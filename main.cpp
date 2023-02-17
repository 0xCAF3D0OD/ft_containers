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
	vector<std::string> letters;

	letters.push_back("abc");
	std::string s = "def";
	letters.push_back(s);

	std::cout << "std::vector `letters` holds: ";
	for (size_t e = 0; e < letters.size(); ++e)
		std::cout << letters[e] << ' ';

	std::cout << "\nMoved-from string `s` holds: " << s << '\n';
}