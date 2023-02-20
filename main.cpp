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
#include <locale>
//#include <iterator>
//#include <list>
//#include <vector>


//int main()
//{
//	vector<int> v;
//	v.push_back(3);
//	v.push_back(1);
//	v.push_back(4);
//	std::cout << "distance(first, last) = "
//			  << ft::distance(v.begin(), v.end()) << '\n'
//			  << "distance(last, first) = "
//			  << ft::distance(v.end(), v.begin()) << '\n';
//	return (0);
//}
//int main()
//{
//	vector<char> q;
//	std::cout.imbue(std::locale("fr_CH.UTF-8"));
//	std::cout << "Maximum size of a std::vector is " << q.max_size() << '\n';
//}
void print(int id, const std::vector<int>& container)
{
	std::cout << id << ". ";
	for (size_t x = 0; x < container.size(); ++x)
		std::cout << x << ' ';
	std::cout << '\n';
}

int main (void)
{
	vector<int> c1;
	std::srand(10);
	for (size_t i = 0; i <= 100; ++i)
		c1.push_back(std::rand());
	print(1, c1);

	vector<int>::iterator it = c1.begin();
	it = c1.insert(it, 200);
	print(2, c1);
}