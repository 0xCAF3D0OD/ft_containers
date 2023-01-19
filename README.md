![img/conta.png](img/conta.png)

## Skills addressed 

* Language C++ version 98.
* STL library container.

## Introduction


* **this project will implement a few container types of the C++ standard template library.**
* We must Implement **3 different** containers:
  * **Associative container:** `Map`.
  * **Sequence container:** `Vector` (without vector<bool>).
  * **Derived container:** `Stack` (use with vector class).


* We must also implement **7 structures** for our containers.
  * `std::iterator_traits`.
  * `std::reverse_iterator`.
  * `std::enable_if`.
  * `std::is_integral`.
  * `std::equal` **and/or** `std::lexicographical_compare`.
  * `std::pair`.
  * `std::make_pair`.

<p align="center">
  <img src="img/cargo.png" width="100">
</p>

## Main concepts

* Containers or container classes **store objects and data**. They are implemented as **class templates**, which allows a 
great flexibility in the types supported as elements. They are part of the 
[**C++ Standard Template Library**](https://github.com/0xCAF3D0OD/CPP/tree/main/module_08)
 
 
* Containers replicate structures very commonly used in programming:
  * **dynamic arrays** (`vector`).
  * queues (queue).
  * **stacks** (`stack`).
  * heaps (priority_queue).
  * linked lists (list).
  * trees (set).
  * **associative arrays** (`map`).


&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
[<img src="img/containers.svg" width="300">]("img/containers.svg")

* There are **seven standards container classes**, **three container adaptor classes** and **seven header files**
that provide access to these containers or container adaptors.
 
 
* `stack`, **queue** and **priority_queue** are implemented as **container adaptors**. Container adaptors are not full container
  classes, but **classes that provide a specific interface relying on an object of one of the container classes to handle
  the elements**.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
[<img src="img/containers_header_file.svg" width="300">]("img/containers_header_file.svg)

## Containers

### Vector
* **`Vectors` are sequence containers representing arrays that can change in size.**
* `Vectors` are the same as `dynamic arrays` with the ability to **resize itself automatically when an element is inserted 
or deleted**, with their storage being handled automatically by the container.


* **[Declaration of Vectors in C++](https://www.mygreatlearning.com/blog/vectors-in-c/)**

  * the C++ **definition of std::vector** from <vector> header library file:
    ````c++
      template < class T, class Allocator = std::allocator<T> > class vector;
      ````
  * `T` - The type of the **element**, may be **substituted by any other data type** including user-defined type.
  * `Allocator` - The Type of **allocator** object. By default, the allocator class template is used. 
  Which defines the memory allocation/de-allocation model, construct/destroy elements and is value-independent.


* **[Initialization of Vectors](https://www.mygreatlearning.com/blog/vectors-in-c/)**

### Map
### Stack
