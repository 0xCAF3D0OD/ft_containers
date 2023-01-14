![img/conta.png](img/conta.png)

---
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
[<img src="img/cpm" width="300">]("img/")

## Containers

### Vector
* **`Vectors` are sequence containers representing arrays that can change in size.**
* `Vectors` are the same as `dynamic arrays` with the ability to **resize itself automatically when an element is inserted 
or deleted**, with their storage being handled automatically by the container.

* **[Declaration of Vectors in C++](https://www.mygreatlearning.com/blog/vectors-in-c/)**

  * **Header:** 
    * ````
      #include<vector>
      ````

* **[Initialization of Vectors](https://www.mygreatlearning.com/blog/vectors-in-c/)**
  * **Vector declaration:**
    * ````
      vector< object_type > vector_variable_name;
      ````
  * **Pushing the values one-by-one in vector using push_back():**
    * All the elements that **need to be stored in the vector** are pushed back one-by-one in the vector using the 
    push_back() method.
    * ````
      vector_name.push_back(element_value);
      ````
  * **Using the overload constructor of the vector Class:**
    * Is used to **populate a vector** with multiple times the **same value**.
    * ````
      vector<object_type> vector_name (number_of_repetition,element_value);
      ````
  * **Using Array:**
    * This method **uses array as a parameter** to be **passed in the vector constructor**.
    * ````
      vector<object_type> vector_name {val1,val2,val3,....,valn};
      ````
  * **Using already initialized vector:**
    * This method uses an already created vector to create a new vector with the same values.
    * ````
      vector<object_type> vector_name_1{val1,val2,…,valn};
      ````
### Map
### Stack
