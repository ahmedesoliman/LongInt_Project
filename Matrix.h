/**
 * @file Matrix.h
 * @author Ahmed Soliman
 * @brief Header file for Matrix class
 * @date 2022-04-29
 *
 */
/**
 * @file Matrix.h
 * @author Mike Boyle
 * @brief Header file for Matrix class
 * @date 2022-04-18
 *
 */

#ifndef MATRIX_H
#define MATRIX_H

#include "Row.h"

using namespace std;

class Matrix
{
private:
    int height;
    int width;
    double **matrix;

public:
    Matrix(int, int, double = 0);
    ~Matrix();
    void print();
    Row &operator[](int i);
    Matrix &operator*(Matrix &);
    int getHeight() const;
    int getWidth() const;
};

#endif