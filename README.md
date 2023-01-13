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
* `stack`, queue and priority_queue are implemented as **container adaptors**. Container adaptors are not full container
  classes, but **classes that provide a specific interface relying on an object of one of the container classes to handle
  the elements**.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
[<img src="img/containers header file.svg" width="300">]("img/containers header file.svg")
