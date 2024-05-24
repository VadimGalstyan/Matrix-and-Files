#pragma once;
#include <iostream>
#include <time.h>

class Matrix
{
public:
	Matrix(int row,int col);
	Matrix(const Matrix& obj);
	Matrix& operator=(const Matrix& obj);
    Matrix(Matrix&& obj);
	Matrix& operator=(Matrix&& obj);
    ~Matrix();
	Matrix& operator++();
	Matrix operator++(int);

public:
    class RowProxy 
    {
    public:
        RowProxy(int* const r);
        int& operator[](const int& index);

    private:
        int* row = nullptr;
    };

    RowProxy operator[](const int& index) const;

public:
    void printSize()const;
	void print() const;
	void matrixInit();

    int getRow() const;
    int getColumn() const;

private:
	int rows = 0;
	int cols = 0;
	int** ptr = nullptr;
};
