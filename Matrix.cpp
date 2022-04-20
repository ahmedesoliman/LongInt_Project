/**
 * @file Matrix.cpp
 * @author Ahmed Soliman ()
 * @brief Implementation file for Matrix class
 * @version 0.1
 * @date 04-20-2022
 *
 * @copyright Copyright (c) 2022
 *
 */

/**
 * @file Matrix.cpp
 * @author Mike Boyle
 * @brief Implementation file for Matrix class
 * @date 2022-04-18
 *
 */

#include <iostream>
#include <stdexcept>
#include "Matrix.h"
#include "Row.h"

using namespace std;

Matrix::Matrix(int h, int w, double initialValue)
{
    if (h < 1 || w < 1)
        throw std::invalid_argument("height and width must be 1 or greater");

    height = h;
    width = w;
    matrix = new double *[height];
    for (int i = 0; i < height; i++)
    {
        matrix[i] = new double[width];
        for (int j = 0; j < width; j++)
            matrix[i][j] = initialValue;
    }
}

Matrix::~Matrix()
{
    delete[] matrix;
}

Row &Matrix::operator[](int i)
{
    if (i < 0 || i > height - 1)
        throw std::invalid_argument("row index out of range");
    Row *r = new Row(matrix[i], width);
    return *r;
}

int Matrix::getHeight() const
{
    return height;
}

int Matrix::getWidth() const
{
    return width;
}

void Matrix::print()
{
    cout << "[";
    for (int i = 0; i < height; i++)
    {
        cout << "[";
        for (int j = 0; j < width; j++)
        {
            cout << matrix[i][j];
            if (j < width - 1)
                cout << " ";
        }
        cout << "]";
        if (i < height - 1)
            cout << endl;
    }
    cout << "]" << endl;
}

Matrix &Matrix::operator*(Matrix &other)
{
    if (width != other.height)
        throw std::invalid_argument("left matrix width must equal right matrix height");

    Matrix *product = new Matrix(height, other.width);
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < other.width; col++)
        {
            // product[row][col] = dot product of row x col
            double sum = 0;
            for (int i = 0; i < width; i++)
                sum += matrix[row][i] * other[i][col];

            (*product)[row][col] = sum;
        }
    }

    return *product;
}
