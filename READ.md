# HugeInteger Arithmetic Library

## Overview
The **HugeInteger Arithmetic Library** is a C++ implementation of an arbitrary-precision integer arithmetic class, `HugeInteger`, designed to handle large integers beyond the limits of built-in types (e.g., `int`, `long long`). This project, developed as part of a Master's degree in Signal Processing and Machine Learning, supports operations like addition, subtraction, multiplication, and comparison for large integers, with a focus on efficiency using advanced algorithms like Number-Theoretic Transform (NTT) for multiplication. The library is suitable for applications requiring high-performance arithmetic, such as cryptographic systems, large-scale data processing, or microservices (e.g., Nokia thesis projects).

## Features
- **Arbitrary-Precision Integers**: Handles positive and negative integers with unlimited digits.
- **Efficient Multiplication**: Uses NTT for O(n log n) multiplication, replacing slower O(n²) methods.
- **Robust Operations**: Supports addition (`+`, `+=`), subtraction (`-`), multiplication (`*`), comparisons (`<`, `>`, `==`), and increment (`++`).
- **File I/O**: Reads integers from text files (e.g., `Hs.txt`) and outputs results to console.
- **Memory Management**: Ensures deep copying and proper deallocation to prevent leaks.
- **Const Correctness**: Adheres to C++ best practices for safe, immutable operations.

## Project Structure
The repository follows a modular structure for maintainability and clarity:
```
.
├── HeaderFiles
│   └── HugeInteger.h        # Class declaration
├── SourceFiles
│   ├── HugeInteger.cpp      # Class implementation (including NTT multiplication)
│   ├── main.cpp             # Demo program
│   └── Hs.txt               # Sample input file
├── README.md                # Project documentation
└── CMakeLists.txt           # CMake build configuration (optional for CLion)
```

- **`HugeInteger.h`**: Declares the `HugeInteger` class with member functions, operators, and private data (`Ds`, `totalDigits`, `isNeg`).
- **`HugeInteger.cpp`**: Implements constructors, operators, utility methods, and NTT-based multiplication.
- **`main.cpp`**: Demonstrates usage by reading from `Hs.txt` and performing arithmetic.
- **`Hs.txt`**: Contains input integers (e.g., `+123`, `-456`) for testing.
- **`CMakeLists.txt`**: Configures build for CLion users (optional).

## HugeInteger Class
The `HugeInteger` class represents large integers with:
- **Private Members**:
  - `int* Ds`: Dynamic array storing digits in reverse order (least significant at `Ds[0]`).
  - `int totalDigits`: Number of digits.
  - `bool isNeg`: Sign flag (`true` for negative).
- **Key Methods**:
  - Constructors: Default, file input (`ifstream`), copy, and size-based.
  - Operators: `+`, `+=`, `-`, `*`, `<`, `>`, `==`, `++`, `[]` (digit access).
  - Utility: `elementWiseAdd`, `elementWiseSubtract`, `trim`, `setInteger`, `clearMemory`.
  - Friend Functions: Stream operators (`>>`, `<<`) for I/O.

### Multiplication Algorithm
The `operator*` uses **Number-Theoretic Transform (NTT)** for efficient multiplication:
- **Why NTT?**: Achieves O(n log n) complexity vs. O(n²) for standard multiplication, critical for large `totalDigits`. NTT uses modular arithmetic (modulo 998244353) for exact integer results, avoiding floating-point errors.
- **How It Works**:
  1. Represents `Ds` arrays as polynomial coefficients.
  2. Pads arrays to a power-of-2 length for NTT.
  3. Applies NTT to transform coefficients to frequency domain.
  4. Performs point-wise multiplication modulo a prime.
  5. Applies inverse NTT to get product coefficients.
  6. Handles carries to compute final digits, updates `totalDigits` and `isNeg`.
- **Implementation**: Replaces a slower repeated-addition approach, leveraging Signal Processing concepts (akin to FFT).

## Dependencies
- **C++20**: Uses modern C++ features (e.g., `std::vector` for NTT, though minimized in core class).
- **Standard Libraries**: `<iostream>`, `<fstream>`, `<string>`, `<vector>`, `<algorithm>`.
- **No External Libraries**: Pure C++ implementation, portable across platforms (tested on macOS arm64).

## Building and Running
### Prerequisites
- **Compiler**: `g++` or `clang++` supporting C++20 (e.g., GCC 11+, Clang 12+).
- **OS**: Tested on macOS; compatible with Linux/Windows.
- **Optional**: CLion for IDE support with CMake.

### Compilation
From the project root:
```bash
g++ -std=c++20 -g -IHeaderFiles SourceFiles/main.cpp SourceFiles/HugeInteger.cpp -o googoo.out
```

### Running
Ensure `Hs.txt` is in `SourceFiles/` with format (e.g., `+123`, `-456`):
```bash
./googoo.out
```
Output depends on `main.cpp` (e.g., prints products like `123 * 456 = +56088`).

### CMake (CLion)
Add `CMakeLists.txt`:
```cmake
cmake_minimum_required(VERSION 3.31)
project(HugeIntegerProject)
set(CMAKE_CXX_STANDARD 20)
include_directories(HeaderFiles)
add_executable(HugeIntegerProject SourceFiles/main.cpp SourceFiles/HugeInteger.cpp)
```
Build and run via CLion’s interface.

## Usage Example
```cpp
#include "HugeInteger.h"
#include <fstream>
#include <iostream>

int main() {
    std::ifstream in("SourceFiles/Hs.txt");
    HugeInteger a(in), b(in);
    HugeInteger sum = a + b;
    HugeInteger product = a * b;
    std::cout << a << " + " << b << " = " << sum << std::endl;
    std::cout << a << " * " << b << " = " << product << std::endl;
    return 0;
}
```
- **Input (`Hs.txt`)**: `+123`, `-456`
- **Output**: `+123 + -456 = -333`, `+123 * -456 = -56088`

## Testing
- **Edge Cases**:
  - Zero: `0 * 123 = 0`
  - Negative: `-123 * -456 = +56088`
  - Large Numbers: Test with `totalDigits` > 1000 from `Hs.txt`.
- **Validation**: Compare results with Python’s `int` or GMP for accuracy.
- **Performance**: NTT ensures O(n log n) for large inputs, verifiable with timing tests.

## Future Improvements
- **Karatsuba Fallback**: Add O(n^1.585) multiplication for smaller `totalDigits` to reduce NTT overhead.
- **Multi-Modulus NTT**: Support larger numbers using multiple primes.
- **Optimization**: Minimize temporary allocations in NTT.
- **Division/Modulus**: Extend `HugeInteger` with division operators.

## Why This Project?
- **Academic**: Demonstrates advanced C++ (const correctness, operator overloading, memory management) and algorithmic skills (NTT, akin to FFT in Signal Processing).
- **Professional**: Aligns with Nokia thesis goals for high-performance microservices, showcasing efficient arithmetic for large-scale systems.
- **Portfolio**: Highlights expertise for interviews (e.g., Nokia, Procountor), combining low-level C++ and algorithmic optimization.

## Contributing
- Fork the repository and submit pull requests for bug fixes or enhancements.
- Report issues via GitHub Issues, including sample inputs (e.g., `Hs.txt`) and expected outputs.
- Follow C++20 conventions and existing naming (e.g., `camelCase` for methods, `PascalCase` for classes).

<!-- ## License
MIT License. See `LICENSE` file (to be added) for details. -->

## Contact
For questions or collaboration, contact via GitHub or email (add your email if desired).

---

*Developed by a Master's student in Signal Processing and Machine Learning, University of Tampere, for academic and professional exploration in high-performance C++ arithmetic.*
