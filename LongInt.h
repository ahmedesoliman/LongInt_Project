/**
 * @file LongInt.h
 * @author Ahmed Soliman ()
 * @brief Header file for LongInt class
 * @version 0.1
 * @date 04-20-2022
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef LONGINTH
#define LONGINTH

#include "DoublyLinkedList.cpp"
#include "ListIterator.h"
#include "Matrix.h"
#include <string>
#include <iostream>

using namespace std;

class LongInt
{

    // Overload operator <<
    friend ostream &operator<<(ostream &, const LongInt &);
    // Overload operator >>
    friend istream &operator>>(istream &, LongInt &);

private:
    DoublyLinkedList<int> digits;
    bool isNegative;
    // compare returns -1 if this is less than other,
    // 1 if this is greater than other,
    // 0 if equal
    int compare(const LongInt &);
    // charToDigit converts a char from '0' to '9' into an int
    int charToDigit(const char &);
    // handleAdd determines which computation to perform when the '+' operator is called
    LongInt *handleAdd(LongInt &, LongInt &);
    // handleSubtract determines which computation to perform when the '-' operator is called
    LongInt *handleSubtract(LongInt &, LongInt &);
    // handleMultiply determines which computation to perform when the '*' operator is called
    LongInt *handleMultiply(LongInt &, LongInt &);
    // handleDivide determines which computation to perform when the '/' operator is called
    LongInt *handleDivide(LongInt &, LongInt &);
    // handleModulo determines which computation to perform when the '%' operator is called
    LongInt *handleModulo(LongInt &, LongInt &);
    // add returns the sum of two LongInts
    LongInt *add(LongInt &, LongInt &);
    // subtract returns the difference of two LongInts (first arg minus second arg)
    LongInt *subtract(LongInt &, LongInt &);
    // multiply returns the product of two LongInts
    LongInt *multiply(LongInt &, LongInt &);
    // divide returns the quotient of two LongInts (first arg divided by second arg)
    // If the last argument is true, it returns the remainder (not the quotient)
    LongInt *divide(LongInt &, LongInt &, bool = false);
    // borrow recursively borrows 1 from a digit's neighbors as part of subtraction
    void borrow(ListIterator<int> &);
    // divideNextStep performs a single step in long division of two LongInts
    void divideNextStep(LongInt &, LongInt &, int &, LongInt &);

public:
    // Default constructor
    LongInt();
    // Construct a long int from a string
    LongInt(const string &);
    // Construct a LongInt from an array of digits, length, bool (assume 1s place is in index 0)
    LongInt(int *, int, bool = false);
    // Construct a LongInt from an int
    LongInt(const int &);

    // getLength() returns the number of digits in the LongInt
    int getLength() const;

    // first() returns an iterator at the first digit in the LongInt
    ListIterator<int> first() const;

    // last() returns an iterator at the last digit in the LongInt
    ListIterator<int> last() const;

    // insertFirst() adds a digit to the front of the LongInt
    void insertFirst(const int &);

    // insertLast() adds a digit to the back of the LongInt
    void insertLast(const int &);

    // deleteLast() removes the digit at the back of the LongInt
    void deleteLast();

    // setIsNegative updates the isNegative property
    void setIsNegative(const bool &);

    // removeTrailingZeroes removes the trailing zeros in a LongInt, ex: "0001" should just be "1"
    void removeTrailingZeroes();

    // toString() returns a string representation of the LongInt
    string toString() const;

    // OPERATOR OVERLOADS
    // Overload operator =
    const LongInt &operator=(const LongInt &);
    // Overload operator ==
    bool operator==(const LongInt &);
    // Overload operator !=
    bool operator!=(const LongInt &);
    // Overload operator <
    bool operator<(const LongInt &);
    // Overload operator <=
    bool operator<=(const LongInt &);
    // Overload operator >
    bool operator>(const LongInt &);
    // Overload operator >=
    bool operator>=(const LongInt &);
    // Overload operator +
    const LongInt &operator+(const LongInt &);
    // Overload operator -
    const LongInt &operator-(const LongInt &);
    // Overload operator *
    const LongInt &operator*(const LongInt &);
    // Overload operator /
    const LongInt &operator/(const LongInt &);
    // Overload operator %
    const LongInt &operator%(const LongInt &);
};

#endif