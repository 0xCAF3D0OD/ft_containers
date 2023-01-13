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
great flexibility in the types supported as elements.
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