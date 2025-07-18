# C++ Module 06

## 📘 Project Overview

**C++ Module 06** focuses on C++ type casting mechanisms. The goal is to understand and implement different types of C++ casts, including scalar type conversions, serialization, and runtime type identification without using standard type information headers.

> **Disclaimer:**  
> This document is an unofficial summary written for educational and documentation purposes.  
> It is not affiliated with or endorsed by 42 or its partners.  
> All 42 students are responsible for adhering to the academic integrity policy.  
> You may **not** publish or share any part of the official subject PDF, evaluation scripts, or Moulinette content.

---

## Contents

- [Goals](#goals)
- [General Requirements](#general-requirements)
- [Additional Rule](#additional-rule)
- [Exercise 00 – Conversion of scalar types](#exercise-00--conversion-of-scalar-types)
- [Exercise 01 – Serialization](#exercise-01--serialization)
- [Exercise 02 – Identify real type](#exercise-02--identify-real-type)
- [Submission Guidelines](#submission-guidelines)

---

## Goals

- Master different types of C++ casting mechanisms.
- Understand scalar type conversions and their limitations.
- Learn pointer serialization and deserialization techniques.
- Implement runtime type identification without standard library helpers.
- Handle edge cases like pseudo-literals (nan, inf) and overflow conditions.

---

## General Requirements

- Written in **C++**, following **C++98 standard**.
- Compile with `c++` and flags `-Wall -Wextra -Werror`.
- Must compile with `-std=c++98` flag.
- No memory leaks or undefined behavior.
- Classes must follow **Orthodox Canonical Form** unless stated otherwise.
- Global variables and `using namespace` are **forbidden**.
- No external libraries (C++11, Boost) allowed.
- No `*printf()`, `*alloc()`, or `free()` functions.
- STL containers and algorithms forbidden until Module 08/09.

### Makefile

Must include standard rules:
- `all`, `clean`, `fclean`, `re`, `$(NAME)`

### Naming Conventions

- Exercise directories: `ex00`, `ex01`, `ex02`
- Class names in `UpperCamelCase`
- Files named after classes: `ClassName.hpp`, `ClassName.cpp`

---

## Additional Rule

**For each exercise, type conversion must be handled using a specific type of casting.**  
Your choice of casting type will be reviewed during defense.

---

## Exercise 00 – Conversion of scalar types

### Overview
Create a `ScalarConverter` class with a static method to convert string representations of C++ literals to different scalar types.

### Requirements

- **Class**: `ScalarConverter` (non-instantiable)
- **Method**: `static void convert(const std::string& literal)`
- **Output types**: `char`, `int`, `float`, `double`

### Supported Input Types

**Character literals:**
- Format: `'c'`, `'a'`, etc.
- Non-displayable characters should show informative message

**Integer literals:**
- Format: `0`, `-42`, `42`, etc.

**Float literals:**
- Format: `0.0f`, `-4.2f`, `4.2f`
- Pseudo-literals: `-inff`, `+inff`, `nanf`

**Double literals:**
- Format: `0.0`, `-4.2`, `4.2`
- Pseudo-literals: `-inf`, `+inf`, `nan`

### Expected Output Format

```
./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0

./convert nan
char: impossible
int: impossible
float: nanf
double: nan

./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0
```

### Implementation Notes

- Detect input type first
- Convert from string to actual type
- Convert explicitly to other three types
- Handle impossible conversions and overflows
- Include headers for numeric limits and special values

---

## Exercise 01 – Serialization

### Overview
Implement a `Serializer` class for pointer serialization and deserialization.

### Requirements

- **Class**: `Serializer` (non-instantiable)
- **Methods**:
  - `static uintptr_t serialize(Data* ptr)`
  - `static Data* deserialize(uintptr_t raw)`

### Functionality

**serialize():**
- Takes a pointer and converts it to `uintptr_t`

**deserialize():**
- Takes `uintptr_t` parameter and converts to `Data*` pointer

### Data Structure

- Create a non-empty `Data` structure with data members
- Test serialization/deserialization roundtrip
- Ensure `deserialize(serialize(ptr))` equals original pointer

---

## Exercise 02 – Identify real type

### Overview
Implement runtime type identification without using `std::typeinfo`.

### Requirements

**Base class:**
- `Base` class with public virtual destructor only

**Derived classes:**
- Three empty classes: `A`, `B`, `C` inheriting from `Base`
- No Orthodox Canonical Form required

### Functions to Implement

**generate():**
```cpp
Base* generate(void);
```
- Randomly instantiates A, B, or C
- Returns instance as Base pointer

**identify() with pointer:**
```cpp
void identify(Base* p);
```
- Prints actual type: "A", "B", or "C"

**identify() with reference:**
```cpp
void identify(Base& p);
```
- Prints actual type: "A", "B", or "C"
- **Forbidden**: Using pointers inside this function

### Constraints

- **Forbidden**: `std::typeinfo` header
- **Forbidden**: `typeinfo` functionality

---

## Submission Guidelines

- Code must be submitted to assigned Git repository
- Only repository contents will be evaluated
- Evaluation includes peer reviews and automated testing
- Double-check folder and file names for correctness
- Any norm or runtime errors stop grading immediately

---

## Testing

Write comprehensive tests for:
- All scalar type conversions
- Edge cases (overflow, impossible conversions)
- Pseudo-literal handling
- Serialization roundtrip accuracy
- Type identification correctness

---

## Final Note

This module introduces fundamental C++ casting concepts essential for type safety and runtime polymorphism. Understanding these mechanisms is crucial for advanced C++ programming and forms the foundation for more complex object-oriented designs.

---
