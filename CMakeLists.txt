cmake_minimum_required(VERSION 3.22)
project(ft_containers)

set(CMAKE_CXX_STANDARD 14)

include_directories(incl)
include_directories(incl/iterators)

add_executable(ft_containers
        incl/iterators/iterator_trait.hpp
        incl/iterators/iterators.hpp
        incl/iterators/random_access_iterator.hpp
        incl/iterators/reverse_iterator.hpp
        incl/utils.hpp
        incl/vector.hpp
        main.cpp)
