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

int main()
{
	ft::vector<std::string> letters;

	letters.push_back("abc");
	std::string s{"def"};
	letters.push_back(std::move(s));

	std::cout << "std::vector `letters` holds: ";
	for (auto&& e : letters) std::cout << std::quoted(e) << ' ';

	std::cout << "\nMoved-from string `s` holds: " << std::quoted(s) << '\n';
}
