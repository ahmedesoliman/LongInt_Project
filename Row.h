/**
 * @file row.h
 * @author Ahmed Soliman ()
 * @brief Header file for Matrix Row
 * @version 0.1
 * @date 04-20-2022
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef ROW_H
#define ROW_H

class Row
{
private:
    double *arr;
    int length;

public:
    Row(double *array, int l);
    ~Row();
    double &operator[](int col);
};

#endif