#include "Vector.h"
#include "Matrix.h"
#include <iostream>

Matrix::Matrix()
{
}

Matrix::Matrix(const Matrix& m)
{
	this->data = new Vector[m.l];
	for (int i = 0; i < m.l; i++)
		this->data[i] = m.data[i];
	this->l = m.l;
	this->c = m.c;
}

Matrix::Matrix(int lines, int columns)
{
	l = lines;
	c = columns;
	data = new Vector[l];
	for (int i = 0; i < l; i++)
		data[i] = Vector(c);
}

Matrix::~Matrix()
{
	delete[] data;
}

Matrix& Matrix::operator=(const Matrix& m)
{
	if (this != &m)
	{
		this->l = m.l;
		this->c = m.c;
		delete[] this->data;
		this->data = new Vector[l];
		for (int i = 0; i < l; i++)
			this->data[i] = m.data[i];
	}
	return *this;
}

Matrix& Matrix::operator+=(const Matrix& m)
{
	if ((this->l != m.l) || (this->c != m.c))
		std::cout << "Err" << std::endl;
	else
	{
		for (int i = 0; i < l; i++)
			this->data[i] += m.data[i];
	}
	return *this;
}

Matrix& Matrix::operator-=(const Matrix& m)
{
	if ((this->l != m.l) || (this->c != m.c))
		std::cout << "Err" << std::endl;
	else
	{
		for (int i = 0; i < l; i++)
			this->data[i] -= m.data[i];
	}
	return *this;
}

Matrix Matrix::operator+(const Matrix& m) const
{
	Matrix result(l, c);
	if ((this->l != m.l) || (this->c != m.c))
		std::cout << "Err" << std::endl;
	else
	{
		for (int i = 0; i < this->l; ++i)
			result.data[i] = this->data[i] + m.data[i];
	}
	return result;
}

Matrix Matrix::operator-(const Matrix& m) const
{
	if ((this->l != m.l) || (this->c != m.c))
		std::cout << "Err" << std::endl;
	else
	{
		Matrix result(l, c);
		for (int i = 0; i < this->l; i++)
			result.data[i] = this->data[i] - m.data[i];
		return result;
	}
}

Matrix Matrix::operator*(double d) const
{
	Matrix result(l, c);
	for (int i = 0; i < l; i++)
		result.data[i] = this->data[i] * d;
	return result;
}

Matrix& Matrix::operator*=(double d)
{
	for (int i = 0; i < l; i++)
		data[i] *= d;
	return *this;
}

Vector& Matrix::operator[](int i)
{
	return data[i];
}

Vector Matrix::operator[](int i) const
{
	return data[i];
}

Matrix Matrix::operator*(const Matrix& m)
{
	if (this->c != m.l) {
		std::cout << "Err" << std::endl;
	}
	else
	{
		Matrix result(this->l, m.c);
		for (int i = 0; i < this->l; i++)
		{
			for (int j = 0; j < m.l; j++)
			{
				for (int k = 0; k < m.l; k++)
				{
					result[i][j] += this->data[i][k] * m.data[k][j];
				}
			}
		}
		return result;
	}
}




void Matrix::printM()
{
	for (int i = 0; i < this->l; i++)
		data[i].print();
	std::cout << std::endl;
}

int Matrix::getLines() const
{
	return this->l;
}
int Matrix::getColumns() const
{
	return  this->c;
}

Matrix operator*(double d, const Matrix& m)
{
	return m * d;
}

std::ostream& operator<<(std::ostream& out, const Matrix& m)
{
	out << std::endl;
	for (int i = 0; i < m.l; i++)
		out << m.data[i] << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, const Matrix& m)
{
	for (int i = 0; i < m.l; i++)
		in >> m.data[i];
	return in;
}

