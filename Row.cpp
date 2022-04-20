/**
 * @file row.cpp
 * @author Ahmed Soliman ()
 * @brief Implementation file for Matrix Row
 * @version 0.1
 * @date 04-20-2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Row.h"
#include <stdexcept>

Row::Row(double *array, int l)
{
    arr = array;
    length = l;
}

Row::~Row()
{
    delete[] arr;
};

double &Row::operator[](int col)
{
    if (col < 0 || col > length - 1)
        throw std::invalid_argument("col index out of range");
    return arr[col];
}