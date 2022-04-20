/**
 * @file main.cpp
 * @author Ahmed Soliman ()
 * @brief
 * @version 0.1
 * @date 04-20-2022
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "LongInt.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

const bool VERBOSE = false;

bool testFunc(const int &, const int &, char);
void displayTestProgress(const double &, const double &);
void testOperation(const char &, const int &, const int &, const int &, const int &, const int &, const int &);
bool testCompare(const int &, const int &);
void testCompareAll();
void testAddAll();
void testSubtractAll();
void testMultiplyAll();
void testDivideAll();
void testModuloAll();
void testVeryLongInts();
void testStringIntOp(const LongInt &, const string &, int &, int &);
void runAllTestCases();
void runAllManualTestCases();
void runManualTestCase();

int main()
{
    cout << "Welcome to the LongInt test driver!" << endl;
    cout << "Let's run some automated tests before we begin!" << endl;
    runAllTestCases();
    cout << endl;
    runAllManualTestCases();
}

void runAllManualTestCases()
{
    char cont;
    cout << "Do you want to do manual testing? (y/n) ";
    cin >> cont;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // disregard return

    while (cont == 'y')
    {
        runManualTestCase();
        cout << "Test another? (y/n) ";
        cin >> cont;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // disregard return
    }

    cout << "OK. Exiting program. Goodbye!" << endl;
}

void runManualTestCase()
{
    LongInt L1, L2, res;
    char op;
    bool invalid = false;
    cout << "Enter a long integer: ";
    cin >> L1;
    cout << "Enter an operator (+, -, *, /, or %): ";
    cin >> op;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // disregard return
    cout << "Enter another long integer: ";
    cin >> L2;

    switch (op)
    {
    case '+':
        res = L1 + L2;
        break;
    case '-':
        res = L1 - L2;
        break;
    case '*':
        res = L1 * L2;
        break;
    case '/':
        res = L1 / L2;
        break;
    case '%':
        res = L1 % L2;
        break;
    default:
        invalid = true;
        break;
    }

    if (!invalid)
        cout << L1 << " " << op << " " << L2 << " = " << res << endl;
    else
        cout << "invalid expression" << endl;
}

bool testFunc(const int &a, const int &b, char op)
{
    LongInt L1(a);
    LongInt L2(b);
    string expected, actual;

    switch (op)
    {
    case '+':
        expected = to_string(a + b);
        actual = (L1 + L2).toString();
        break;
    case '-':
        expected = to_string(a - b);
        actual = (L1 - L2).toString();
        break;
    case '*':
        expected = to_string(a * b);
        actual = (L1 * L2).toString();
        break;
    case '/':
        expected = to_string(a / b);
        actual = (L1 / L2).toString();
        break;
    case '%':
        expected = to_string(a % b);
        actual = (L1 % L2).toString();
        break;
    default:
        cout << "invalid op " << op << endl;
        return false;
    }

    if (VERBOSE && expected != actual)
    {
        cout << a << " " << op << " " << b << ", expected: " << expected
             << ", actual: " << actual << endl;
    }

    return expected == actual;
}

void displayTestProgress(const double &passed, const double &total)
{
    if ((int)passed % 317 == 0 || passed == total)
    {
        cout << "passed " << (int)((passed / total) * 100) << "% (" << passed
             << " of " << total << ")"
             << "\r";
        cout.flush();
    }
}

void testOperation(
    const char &op,
    const int &lowerA,
    const int &upperA,
    const int &stepA,
    const int &lowerB,
    const int &upperB,
    const int &stepB)
{
    double passed = 0;
    double total = 0;
    bool canCompute = true;

    // loop through all numbers twice; first to get total, then to test
    for (int i = 0; i < 2; i++)
    {
        for (int a = lowerA; a < upperA; a += stepA)
        {
            for (int b = lowerB; b < upperB; b += stepB)
            {
                // do not divide by zero
                if ((op == '/' || op == '%') && b == 0)
                    canCompute = false;
                else
                    canCompute = true;

                if (canCompute)
                {
                    if (i == 0)
                        total++;
                    else
                    {
                        passed += testFunc(a, b, op);
                        displayTestProgress(passed, total);
                    }
                }
            }
        }
    }

    cout << "passed " << (int)((passed / total) * 100) << "% (" << passed
         << " of " << total << ")" << endl;
}

bool testCompare(const int &a, const int &b)
{
    LongInt L1(a);
    LongInt L2(b);

    int numOps = 6;
    string boolToString[] = {"false", "true"};
    string ops[] = {"==", "!=", "<", "<=", ">", ">="};
    bool expected[] = {
        (a == b), (a != b), (a < b), (a <= b), (a > b), (a >= b)};
    bool actual[] = {
        (L1 == L2), (L1 != L2), (L1 < L2), (L1 <= L2), (L1 > L2), (L1 >= L2)};

    for (int i = 0; i < numOps; i++)
    {
        bool currExpected = expected[i];
        bool currActual = actual[i];
        if (currExpected != currActual)
        {
            cout << "Uh-oh! Expected " << L1 << " " << ops[i] << " " << L2
                 << " to be " << boolToString[currExpected]
                 << " but got: " << boolToString[currActual] << endl;
            return false;
        }
    }

    return true;
}

void testCompareAll()
{
    cout << "testing comparison operators..." << endl;
    double total = 12;
    double passed = 0;
    passed += testCompare(12345, 12345);
    passed += testCompare(-12345, -12345);
    passed += testCompare(-12345, 12345);
    passed += testCompare(12345, -12345);
    passed += testCompare(1234, 12345);
    passed += testCompare(-1234, -12345);
    passed += testCompare(12345, 1234);
    passed += testCompare(-12345, -1234);
    passed += testCompare(12345, 10095);
    passed += testCompare(-12345, -10095);
    passed += testCompare(19000, 15999);
    passed += testCompare(-19000, -15999);

    cout << "passed " << (passed / total) * 100 << "% ("
         << passed << " of " << total << ")" << endl;
}

void testStringIntOp(const LongInt &actual, const string &expected, int &passed, int &total)
{
    total++;
    if (actual.toString() == expected)
        passed++;
    else if (VERBOSE)
        cout << "fail " << actual << " " << expected << endl;
}

void testVeryLongInts()
{
    cout << "testing very long ints..." << endl;
    int total = 0;
    int passed = 0;

    LongInt L1("1111111111111111111111111");
    LongInt L2("2222222222222222222222222");
    LongInt L3("3333333333333333333333333");
    LongInt L19("123456789");
    LongInt L91("987654321");
    LongInt negL1(L1);
    negL1.setIsNegative(true);
    LongInt negL2(L2);
    negL2.setIsNegative(true);
    LongInt negL3(L3);
    negL3.setIsNegative(true);

    // addition
    testStringIntOp(L1 + L2, L3.toString(), passed, total);
    testStringIntOp(L2 + L1, L3.toString(), passed, total);
    testStringIntOp(negL1 + L2, L1.toString(), passed, total);
    testStringIntOp(L2 + negL1, L1.toString(), passed, total);
    testStringIntOp(negL1 + negL2, negL3.toString(), passed, total);
    testStringIntOp(negL2 + negL1, negL3.toString(), passed, total);
    testStringIntOp(negL3 + L3, "0", passed, total);
    testStringIntOp(L3 + negL3, "0", passed, total);
    testStringIntOp(L19 + L91, "1111111110", passed, total);
    testStringIntOp(L91 + L19, "1111111110", passed, total);

    // subtraction
    testStringIntOp(L3 - L2, L1.toString(), passed, total);
    testStringIntOp(L2 - L3, negL1.toString(), passed, total);
    testStringIntOp(L3 - L1, L2.toString(), passed, total);
    testStringIntOp(L1 - L3, negL2.toString(), passed, total);
    testStringIntOp(L2 - L1, L1.toString(), passed, total);
    testStringIntOp(L1 - L2, negL1.toString(), passed, total);
    testStringIntOp(L2 - L2, "0", passed, total);
    testStringIntOp(negL2 - negL2, "0", passed, total);
    testStringIntOp(L1 - L3, negL2.toString(), passed, total);
    testStringIntOp(negL1 - negL2, L1.toString(), passed, total);
    testStringIntOp(negL2 - negL1, negL1.toString(), passed, total);
    testStringIntOp(L1 - negL2, L3.toString(), passed, total);
    testStringIntOp(negL2 - L1, negL3.toString(), passed, total);

    // multiplication
    testStringIntOp(L1 * LongInt(3), L3.toString(), passed, total);
    testStringIntOp(L2 * L3, "7407407407407407407407405925925925925925925925926", passed, total);
    testStringIntOp(L3 * L2, "7407407407407407407407405925925925925925925925926", passed, total);
    testStringIntOp(negL2 * L3, "-7407407407407407407407405925925925925925925925926", passed, total);
    testStringIntOp(L3 * negL2, "-7407407407407407407407405925925925925925925925926", passed, total);
    testStringIntOp(negL2 * negL3, "7407407407407407407407405925925925925925925925926", passed, total);
    testStringIntOp(negL3 * negL2, "7407407407407407407407405925925925925925925925926", passed, total);
    testStringIntOp(L19 * L91, "121932631112635269", passed, total);
    testStringIntOp(L91 * L19, "121932631112635269", passed, total);

    // division
    testStringIntOp(L3 / L2, "1", passed, total);
    testStringIntOp(L2 / L3, "0", passed, total);
    testStringIntOp(negL3 / L2, "-1", passed, total);
    testStringIntOp(L2 / negL3, "0", passed, total);
    testStringIntOp(negL3 / negL2, "1", passed, total);
    testStringIntOp(negL2 / negL2, "1", passed, total);
    testStringIntOp(L91 / L19, "8", passed, total);

    // modulo
    testStringIntOp(L91 % L19, "9", passed, total);
    testStringIntOp(L19 % L91, L19.toString(), passed, total);
    testStringIntOp(L3 % L1, "0", passed, total);

    displayTestProgress(passed, total);
    cout << endl;
}

void testAddAll()
{
    cout << "testing addition..." << endl;
    testOperation('+', -1001, 1001, 13, -10001, 10001, 47);
}

void testSubtractAll()
{
    cout << "testing subtraction..." << endl;
    testOperation('-', -1001, 1001, 13, -10001, 10001, 47);
}

void testMultiplyAll()
{
    cout << "testing multiplication..." << endl;
    testOperation('*', -1001, 1001, 13, -10001, 10001, 47);
}

void testDivideAll()
{
    cout << "testing division..." << endl;
    testOperation('/', -10001, 10001, 47, -1001, 1001, 13);
}

void testModuloAll()
{
    cout << "testing modulo..." << endl;
    testOperation('%', -1001, 1001, 7, -101, 101, 1);
}

void runAllTestCases()
{
    testCompareAll();
    testAddAll();
    testSubtractAll();
    testMultiplyAll();
    testDivideAll();
    testModuloAll();
    testVeryLongInts();
}
