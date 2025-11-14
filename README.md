# Infix to Postfix Evaluator

A C++ implementation of an expression evaluator that converts infix notation mathematical expressions to postfix (Reverse Polish Notation) and evaluates them.

## Overview

This project implements a complete expression evaluation system using custom data structures. It includes:

- **Doubly Linked List**: A generic template-based doubly linked list implementation
- **Stack**: A generic template-based stack built on top of the doubly linked list
- **Infix to Postfix Converter**: Converts standard mathematical expressions (infix notation) to postfix notation
- **Postfix Evaluator**: Evaluates postfix expressions and returns the result

## Features

- ✅ Generic template-based data structures (List and Stack)
- ✅ Support for basic arithmetic operators: `+`, `-`, `*`, `/`
- ✅ Parentheses support for expression grouping
- ✅ Operator precedence handling (multiplication/division before addition/subtraction)
- ✅ Comprehensive test suite with multiple test cases
- ✅ Single-digit operand support

## Building the Project

### Prerequisites

- C++ compiler with C++14 support (g++, clang++)
- CMake 3.21 or higher
- Make

### Build Instructions

1. Clone the repository:
```bash
git clone https://github.com/robertbiv/infix-to-postfix-evaluator.git
cd infix-to-postfix-evaluator
```

2. Create a build directory and compile:
```bash
mkdir build
cd build
cmake ..
make
```

3. Run the executable:
```bash
./HW_5
```

## Usage

### Running Tests

The project includes a comprehensive test suite. Simply run the executable to execute all tests:

```bash
./HW_5
```

Expected output:
```
Test List<char> class
  test List  1: success
  ...
  
Test Stack<int> class
  test List  1: success
  ...

Test Rpn() and Eval()
  test Rpn   1: success
  test Eval  1: success
  ...

Congratulation!
You successfully passed all tests!
```

### Example Conversions

The program converts and evaluates the following expressions:

| Infix Expression | Postfix Expression | Result |
|-----------------|-------------------|--------|
| `1+2;` | `12+;` | 3 |
| `1+2*3;` | `123*+;` | 7 |
| `1+2*3/4-5;` | `123*4/+5-;` | -2.5 |
| `(1+2)*3;` | `12+3*;` | 9 |
| `1+2+3*(4+(5+6)*7);` | `12+3456+7*+*+;` | 246 |

## Code Structure

### Core Components

- **`list.h`**: Doubly linked list implementation
  - Template class supporting any data type
  - Operations: AddToHead, AddToTail, RemoveHead, RemoveTail
  - Maintains head and tail pointers for efficient operations

- **`stack.h`**: Stack implementation using the doubly linked list
  - Template class supporting any data type
  - Operations: Push, Pop, Top, Clear, IsEmpty
  - LIFO (Last In, First Out) data structure

- **`calcimpl.cpp`**: Core algorithm implementations
  - `InfixToPostfix()`: Converts infix expressions to postfix notation
  - `EvaluatePostfix()`: Evaluates postfix expressions
  - `Operand()`: Checks if a character is a digit
  - `Precedence()`: Returns operator precedence

- **`calctest.cpp`**: Test suite
  - Tests for List class functionality
  - Tests for Stack class functionality
  - Tests for infix to postfix conversion
  - Tests for postfix evaluation

### Algorithm Details

#### Infix to Postfix Conversion

The algorithm uses a stack to reorder operators according to their precedence:

1. Scan the infix expression from left to right
2. If operand (digit), add to output
3. If `(`, push to stack
4. If operator, pop operators with higher/equal precedence to output, then push current operator
5. If `)`, pop operators until `(` is found
6. If `;`, pop all remaining operators to output

#### Postfix Evaluation

The algorithm uses a stack to evaluate the expression:

1. Scan the postfix expression from left to right
2. If operand, push to stack
3. If operator, pop two operands, apply operation, push result back
4. Final stack value is the result

## Limitations

- Currently supports only single-digit operands (0-9)
- Supports basic arithmetic operators only (+, -, *, /)
- Expressions must end with a semicolon (;)

## Future Enhancements

Potential improvements for this project:

- [ ] Support for multi-digit numbers
- [ ] Support for floating-point numbers
- [ ] Additional operators (^, %, etc.)
- [ ] Support for mathematical functions (sin, cos, etc.)
- [ ] Error handling for invalid expressions
- [ ] Interactive calculator mode

## Author

Robert Bennethum

## License

This project is available for educational purposes.
