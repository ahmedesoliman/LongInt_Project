### Long Integer Project

- Programmer: Ahmed Soliman
- Date: 2022-04-18
- Section: CSC-331H

This project implements a LongInt class to represent arbitraily large positive and negative integers. Typical int classes use bits to represent an integer. This means an integer class of n bits is limited to integers within +/- 2^n (e.g., 2^32 in the case of a 32 bit integer and even less if it is a signed int). LongInt gets around this by representing each digit of the number as a node in a doubly linked list.2

- DoublyLinkedList.cpp
- DoublyLinkedList.h
- ListIterator.cpp
- ListIterator.h
- Node.h

In addition, LongInt requires the following files for its multiplication function:

- Matrix.cpp
- Matrix.h
- Row.cpp
- Row.h

### LongInt Class

includes:

1. Operator functions to overload the operators +, -, \*, /, %
2. Operator functions to overload the operators ==, <, <=, >, >=
3. An operator function to overload the operator <<
4. An operator function to overload the operator >>

### Usage

To use the LongInt class in your program, you'll need to #include "LongInt.h".

You can then construct and use instances of the class. For example:

```
// construct from a string
LongInt L1("1234567890");

// construct from an int
LongInt L2(88888);

// construct from user input
LongInt L3;
cout << "Enter a long int: ";
cin >> L3;
cout << L3;

// Comparisions
cout << L1 == L2 << endl;
cout << L1 <= L2 << endl;
// etc.

// Arithmetic
cout << L1 + L2 << endl;
cout << L1 - L2 << endl;
cout << L1 * L2 << endl;
cout << L1 / L2 << endl;
cout << L1 % L2 << endl;
```

### Automated testing

The driver program (main.cpp) runs automated tests on the comparison and arithmetic functions of LongInt. These cases are generated by looping through two sequences of numbers and checking the addition, subtraction, multiplication, division, and modulo operators for all valid combinations of the two numbers. In total there are more than 300,000 test cases, and the program will display the ongoing progress of each test.

### Manual testing

When the automated tests are completed, main.cpp will allow users to manually create long ints and test their addition, subtraction, multiplication, division, and modulo operations.

### Compiling and running the driver

To run the tester on the replit.com repo, simply press the Run button.

To compile and run locally:

1. Ensure all project files are in the same folder.
2. Compile main.cpp: g++ main.cpp Matrix.cpp Row.cpp LongInt.cpp -o main.
3. Run the compiled executable: ./main

## Implementation notes

### Basic operations

- Addition and subtraction are handled in a way very similar to how a human would manually add up long integer sums, with carrying and borrowing.
  Division is handled in a way very similar to manual long division, one digit at a time. To determine the correct digit in the answer, repeated subtraction is used. However because this mirrors long division, the maximum number of repeated subtractions is `9 * <number of digits in dividend>`.

- Modulo uses the same procedures as division, except we return the final remainder instead of the quotient. Modulo also has many more cases where we can get an answer without doing any division at all (for example, a smaller number modulo a larger number), so it is noticeably faster.

- Multiplication is handled in a very different way, using matrix multiplication. Please see my github gist for a longer explanation of how this works. The runtime efficiency of this way of multiplication is still quadratic, but that is in terms of the number of digits -- not the actual size of the integer. This is a great improvement over a brute force method such as repeated addition.

### Operation handlers

- I made a design decision to make the add, subtract, multiply, divide, and modulo functions as basic as possible. These functions expect to receive only positive numbers and expect to output only positive numbers. In the case of subtracting a - b for example, the subtract() function expects a and b to be positive, and for a to be greater than or equal to b.

- Because we still need to carry out math that does not meet those requirements, thehandle\*\*\* functions transform the more complicated operations into simpler ones. For example:

  - If the client code is -34 + 68, the handleAdd() function will actually interpret this as 68 - 34 and call subtract(68, 34).

  - Multiplication and division with negatives is handled in the handleMultiply() and handleDivide() functions. Ex: -12 \* 20 is delegated to multiply(12, 20) and the resulting product is converted to a negative number.

  - The handle\*\*\* functions also catch simpler cases where the full operation is not necessary, such as subtracting or dividing a number by itself, or dividing a smaller number by a larger number (which in integer division is simply zero).
