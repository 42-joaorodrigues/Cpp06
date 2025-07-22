# C++ Module 06

![42 Badge](https://img.shields.io/badge/42-C++_Module_06-brightgreen)
![C++ Badge](https://img.shields.io/badge/Language-C++-blue)
![Status Badge](https://img.shields.io/badge/Status-Completed-success)

## What I Learned

Through this advanced C++ casting module at 42 School, I developed critical knowledge in type safety and runtime polymorphism:

- **C++ casting mechanisms** - Mastered static_cast, dynamic_cast, and reinterpret_cast for safe type conversions
- **Scalar type conversion** - Implemented robust string-to-type parsing with comprehensive error handling
- **Memory address manipulation** - Used reinterpret_cast for low-level pointer serialization and deserialization
- **Runtime type identification** - Implemented RTTI without std::typeinfo using dynamic_cast and exception handling
- **Exception-based control flow** - Leveraged try-catch blocks for elegant type detection in reference contexts
- **Numeric limits handling** - Worked with special floating-point values (NaN, infinity) and overflow detection
- **String parsing algorithms** - Developed sophisticated input validation for multiple literal formats
- **Polymorphism patterns** - Applied virtual destructors and inheritance for runtime type determination
- **Safe casting practices** - Learned when and how to use different cast types for maximum type safety
- **Edge case management** - Handled impossible conversions and boundary conditions gracefully

This module enhanced my understanding of C++ type system intricacies and safe programming practices essential for robust software development.

## About the Project

C++ Module 06 explores advanced type casting mechanisms in C++. It demonstrates three fundamental concepts: scalar type conversion, pointer serialization, and runtime type identification. These exercises showcase different casting operators and their appropriate use cases in real-world scenarios.

## Implementation Details

The module consists of three progressive exercises that build upon C++ casting fundamentals:

### Exercise 00: ScalarConverter - Type Conversion Engine

A static utility class that converts string literals to multiple scalar types with comprehensive validation:

**Key Features:**
- **Smart input detection**: Automatically identifies char literals ('c'), numeric values, and special literals
- **Robust parsing**: Uses `strtod()` with complete error checking and endptr validation
- **Special value handling**: Properly processes NaN, +inf, -inf with appropriate suffix handling
- **Boundary checking**: Validates conversions against numeric_limits for overflow prevention
- **Formatted output**: Displays results with proper precision and displayability checks

**Supported Input Formats:**
| Type | Examples | Special Cases |
|------|----------|---------------|
| char | 'a', 'Z', '0' | Non-displayable handling |
| int | 42, -123, 0 | Overflow detection |
| float | 42.0f, -4.2f | nanf, +inff, -inff |
| double | 42.0, -4.2 | nan, +inf, -inf |

**Implementation Highlights:**
```cpp
// Intelligent literal detection
if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
    val = str[1];  // Character literal
else if (str == "nan" || str == "nanf")
    val = std::numeric_limits<double>::quiet_NaN();
```

### Exercise 01: Serializer - Pointer Address Manipulation

A non-instantiable utility class for safe pointer serialization using reinterpret_cast:

**Core Functionality:**
- **serialize()**: Converts `Data*` to `uintptr_t` using reinterpret_cast
- **deserialize()**: Converts `uintptr_t` back to `Data*` with guaranteed roundtrip accuracy
- **Data structure**: Custom struct with meaningful members (id, name, age)

**Technical Implementation:**
```cpp
static uintptr_t serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

static Data* deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}
```

**Validation Approach:**
- Demonstrates perfect roundtrip: `deserialize(serialize(ptr)) == ptr`
- Preserves data integrity through pointer manipulation
- Uses reinterpret_cast for low-level memory address casting

### Exercise 02: Runtime Type Identification Without RTTI

Implements dynamic type detection using inheritance and casting without std::typeinfo:

**Class Hierarchy:**
```cpp
Base (virtual destructor) → A, B, C (empty derived classes)
```

**Type Detection Strategies:**

**Pointer-based identification** (using dynamic_cast):
```cpp
void identify(Base *p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    // Chain continues for B and C
}
```

**Reference-based identification** (using exceptions):
```cpp
void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (...) {} // Continue to next type
}
```

**Random generation**: Uses time-seeded random number generation for object instantiation

## Usage

```bash
# Exercise 00: Scalar Conversion
cd ex00 && make
./convert "42.0f"
./convert "'a'"
./convert "nan"

# Exercise 01: Serialization
cd ex01 && make
./serializer

# Exercise 02: Type Identification
cd ex02 && make
./identify
```

## Integration Example

```cpp
// Exercise 00: Type conversion with validation
ScalarConverter::convert("123.45f");
// Output:
// char: '{'
// int: 123
// float: 123.5f
// double: 123.5

// Exercise 01: Safe pointer manipulation
Data original = {42, "Test", 25};
uintptr_t serialized = Serializer::serialize(&original);
Data* recovered = Serializer::deserialize(serialized);
assert(recovered == &original); // Guaranteed success

// Exercise 02: Runtime type detection
Base* mystery = generate();
identify(mystery);    // Prints: A, B, or C
identify(*mystery);   // Same result via reference
delete mystery;
```

## Technical Challenges Overcome

- **Comprehensive input validation** - Implemented bulletproof string parsing with complete error handling
- **Special floating-point values** - Correctly handled IEEE 754 special cases (NaN, infinity)
- **Cast safety hierarchy** - Applied appropriate cast types: static_cast for safe conversions, dynamic_cast for polymorphic types, reinterpret_cast for low-level operations
- **Exception-based control flow** - Used exceptions elegantly for reference-based type detection without pointers
- **Numeric overflow detection** - Implemented precise boundary checking using std::numeric_limits
- **Orthodox Canonical Form** - Made utility classes non-instantiable while maintaining proper form

---

*This project was completed as part of the 42 School curriculum, demonstrating my mastery of advanced C++ casting mechanisms, type safety principles, and runtime polymorphism techniques.*

---

## License

This project is licensed under the [MIT License](./LICENSE).
