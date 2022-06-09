#pragma once
#include <iostream>
#include"Vector.h"

#include "Vector.h"
#include <iostream>

class Matrix {
private:
	Vector* data = 0;
	int l = 0;
	int c = 0;
public:
	Matrix();
	Matrix(const Matrix& m);
	Matrix(int lines, int columns);
	~Matrix();

	Matrix& operator=(const Matrix& m);
	Matrix& operator+=(const Matrix& m);
	Matrix& operator-=(const Matrix& m);
	Matrix operator+(const Matrix& m) const;
	Matrix operator-(const Matrix& m) const;
	Matrix operator*(double d) const;
	Matrix& operator*=(double d);
	Vector& operator[](int i);
	Vector operator[](int i) const;
	Matrix operator*(const Matrix& m);

	friend Matrix operator*(double d, const Matrix& m);
	friend std::ostream& operator<<(std::ostream& out, const Matrix& m);
	friend std::istream& operator>>(std::istream& in, const Matrix& m);

	void printM();
	int getLines() const;
	int getColumns() const;

};