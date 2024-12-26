# 🛠️ Push Swap - 42 Project and Checker

<p align="center">
  <img src="https://github.com/leogaudin/42_project_badges/raw/main/badges/push_swap_bonus.webp" />
</p>

Welcome to **Push Swap**, a project at 42 that involves sorting a stack of integers using a limited set of operations. The project includes a checker program to verify the correctness of your sorting algorithm.

---

## 📋 Project Overview

| **Category**            | **Functions**                                                                                           |
|-------------------------|--------------------------------------------------------------------------------------------------------|
| **Main Program**         | `push_swap` - Sorting the stack using a series of moves.                                                 |
| **Checker Program**      | `checker` - Verifying if the sorting process is correct and if the stack is properly sorted after execution. |
| **Utility Functions**    | `ft_putnbr`, `ft_putstr`, `ft_putchar`, `ft_strdup`, `ft_split`                                         |

---

## 🚀 Key Features

1. **Sorting Algorithm**:
   - The main goal of this project is to implement a sorting algorithm that sorts a stack of integers using a limited set of operations, such as `sa`, `sb`, `pa`, `pb`, `ra`, `rb`, `rra`, and `rrb`.
   
2. **Checker**:
   - The checker allows you to validate if your sorting algorithm is working correctly by checking if the stack is sorted at the end. It reads a series of commands and applies them to the stack, checking the final result.

3. **Efficient Stack Management**:
   - Utilizes linked lists to manage the stacks effectively, ensuring optimal performance for sorting operations.

4. **Optimization**:
   - The project emphasizes optimizing the algorithm to minimize the number of operations needed to sort the stack.

---

## 🗂️ File Structure

| **File**                | **Description**                                                                                        |
|-------------------------|--------------------------------------------------------------------------------------------------------|
| `Makefile`              | Automates the compilation process. Run `make` to generate the `push_swap` executable.                   |
| `push_swap.h`           | Header file with function prototypes and necessary includes.                                           |
| `push_swap.c`           | Main program implementing the sorting logic.                                                           |
| `checker.c`             | The checker program used to verify the correctness of the sorting algorithm.                           |
| `utils.c`               | Utility functions like `ft_putnbr`, `ft_putstr`, `ft_putchar`, `ft_strdup`, `ft_split`, etc.           |
| `stack.c`               | Functions for managing the stack using linked lists, including pushing and popping elements.           |

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

Once compiled, you can use the push_swap and checker programs as follows:

Sorting the stack:
To sort a stack, run the push_swap program with a series of integers as input:
```bash
./push_swap 3 2 1
```
This will output the series of moves required to sort the stack in the fewest possible operations.

Checking the result:
To verify if the sorting algorithm worked correctly, use the checker program:
```bash
./checker 3 2 1
```
This will read the sequence of moves from standard input, apply them, and check if the stack is sorted.

---
