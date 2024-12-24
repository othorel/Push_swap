# 🧩 Push Swap - 42 Project for Sorting Integers with Stacks

<p align="center">
  <img src="https://github.com/leogaudin/42_project_badges/raw/main/badges/push_swap.webp" />
</p>

Welcome to **Push Swap**, a C project that challenges you to sort a stack of integers using two stacks (**A** and **B**) with a minimal number of operations. This project emphasizes algorithm optimization and understanding stack-based data structures.

---

<p align="center">
  <img src="https://raw.githubusercontent.com/42ProjectBadges/main/badges/42-42badge.png" />
</p>

---

## 📋 Project Overview

| **Category**              | **Functions**                                                                                      |
|---------------------------|---------------------------------------------------------------------------------------------------|
| **Sorting Algorithm**     | `quick_sort`, `merge_sort`                                                                       |
| **Stack Operations**      | `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`                              |
| **Optimization**          | `find_best_move`, `calculate_cost`                                                              |

---

## 🚀 Key Features

1. **Stack-Based Sorting**:
   - Utilize two stacks (**A** and **B**) to sort integers in ascending order with predefined operations.

2. **Efficient Operations**:
   - Minimize the number of operations required to sort the stack using combinations of swaps, pushes, and rotations.

3. **Input Validation**:
   - Ensure the program handles edge cases, such as duplicate values, non-numeric inputs, and integers outside the valid range.

4. **Algorithmic Thinking**:
   - Explore and implement efficient sorting strategies tailored to stack manipulation.

---

## 🗂️ File Structure

| **File**         | **Description**                                                                 |
|-------------------|---------------------------------------------------------------------------------|
| `Makefile`        | Automates the build process. Run `make` to compile the project.                 |
| `push_swap.h`     | Header file with function prototypes and necessary includes.                    |
| `push_swap.c`     | Main implementation file. Parses input and initiates the sorting process.       |
| `operations.c`    | Contains stack manipulation functions such as `sa`, `pb`, `ra`, etc.            |
| `algorithm.c`     | Implements sorting logic and optimization strategies.                           |
| `utils.c`         | Helper functions for validation, error handling, and memory management.         |

---

## 🔧 Compilation Instructions

Use the **Makefile** to compile the project.

- **Compile the project:**
  ```bash
  make
  ```
- **Clean the project (remove object files):**
  ```bash
  make clean
  ```
- **Full cleanup (remove all generated files):**
  ```bash
  make fclean
  ```
- **Recompile after cleaning:**
  ```bash
  make re
  ```
  ---

## 💻 Usage
  
Once compiled, you can use the Push Swap program as follows:

Running the Push Swap Program
Provide a list of integers as arguments. The program will output the sequence of operations to sort the stack.
```bash
./push_swap [integers]
```
Example:
```bash
./push_swap 3 2 1
```
Output:
```bash
pb
sa
pa
```
---

## 🧪 Testing

Test the program with various cases to ensure robustness:

1 Basic Test:
```bash
./push_swap 3 2 1
```
2 Large Inputs:
```bash
./push_swap $(seq 1 500 | shuf)
```
3 Checker Validation:
```bash
ARG="3 2 1"; ./push_swap $ARG | ./checker_linux $ARG
```
---
## 🌟 Algorithms

The project encourages the use of efficient sorting algorithms such as:

Insertion Sort (for small stacks).
Quick Sort-based partitioning (for larger stacks).

---

## 🤝 Contributing

If you'd like to contribute to this project, feel free to fork the repository, submit your changes, and create a pull request!

---
