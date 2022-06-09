#include <iostream>
#include"Vector.h"

Vector::Vector()
{

}

Vector::Vector(int n)
{
	this->n = n;
	data = new double[n];
	for (int i = 0; i < n; ++i)
		data[i] = 0.;
}

void Vector::resize(int newSize)
{
	double* copy = new double[newSize];
	for (int i = 0; i < this->n; i++)
		copy[i] = data[i];
	delete[] data;
	data = copy;
	this->n = newSize;
}

Vector::Vector(const Vector& v)
{
	this->resize(v.n);
	for (int i = 0; i < this->n; ++i)
		this->data[i] = v.data[i];
}

Vector::~Vector()
{
	delete[] data;
}

Vector& Vector::operator=(const Vector& v)
{
	if (this->data != v.data)
	{
		this->resize(v.n);
		for (int i = 0; i < v.n; i++)
			this->data[i] = v.data[i];
	}
	return *this;
}

Vector Vector::operator+(const Vector& v) const
{
	int max = this->n > v.n ? this->n : v.n;
	Vector result(max);
	if (this->n > v.n)
	{
		for (int i = 0; i < v.n; i++)
			result.data[i] = v.data[i] + this->data[i];
		for (int i = v.n; i < this->n; i++)
			result.data[i] = this->data[i];
		return result;
	}
	else if (this->n < v.n)
	{
		for (int i = 0; i < this->n; i++)
			result.data[i] = v.data[i] + this->data[i];
		for (int i = this->n; i < v.n; i++)
			result.data[i] = v.data[i];
		return result;
	}
	else for (int i = 0; i < this->n; i++)
		result.data[i] = v.data[i] + this->data[i];
	return result;
}

Vector& Vector::operator+=(const Vector& v)
{
	if (this->n > v.n)
	{
		for (int i = 0; i < v.n; i++)
			this->data[i] = v.data[i] + this->data[i];
		for (int i = v.n; i < this->n; i++)
			this->data[i] = this->data[i];
		return *this;
	}
	else if (this->n < v.n)
	{
		for (int i = 0; i < this->n; i++)
			this->data[i] = v.data[i] + this->data[i];
		for (int i = this->n; i < v.n; i++)
			this->data[i] = v.data[i];
		return *this;
	}
	else for (int i = 0; i < this->n; i++)
		this->data[i] = v.data[i] + this->data[i];
	return *this;
}

Vector Vector::operator-(const Vector& v) const
{
	int max = this->n > v.n ? this->n : v.n;
	Vector result(max);
	if (this->n > v.n)
	{
		for (int i = 0; i < v.n; i++)
			result.data[i] = this->data[i] - v.data[i];;
		for (int i = v.n; i < this->n; i++)
			result.data[i] = this->data[i];
		return result;
	}
	else if (this->n < v.n)
	{
		for (int i = 0; i < this->n; i++)
			result.data[i] = this->data[i] - v.data[i];;
		for (int i = this->n; i < v.n; i++)
			result.data[i] = v.data[i];
		return result;
	}
	else for (int i = 0; i < this->n; i++)
		result.data[i] = this->data[i] - v.data[i];
	return result;
}

Vector& Vector::operator-=(const Vector& v)
{
	if (this->n > v.n)
	{
		for (int i = 0; i < v.n; i++)
			this->data[i] = this->data[i] - v.data[i];;
		for (int i = v.n; i < this->n; i++)
			this->data[i] = this->data[i];
		return *this;
	}
	else if (this->n < v.n)
	{
		for (int i = 0; i < this->n; i++)
			this->data[i] = this->data[i] - v.data[i];;
		for (int i = this->n; i < v.n; i++)
			this->data[i] = v.data[i];
		return *this;
	}
	else for (int i = 0; i < this->n; i++)
		this->data[i] = this->data[i] - v.data[i];
	return *this;
}

Vector Vector::operator*(double a) const
{
	Vector result(n);
	for (int i = 0; i < n; i++)
		result.data[i] = this->data[i] * a;
	return result;
}

Vector& Vector::operator*=(double a)
{
	for (int i = 0; i < n; i++)
		this->data[i] = this->data[i] * a;
	return *this;
}

double Vector::dot(const Vector& v)	const
{
	double result = 0;
	for (int i = 0; i < n; i++)
		result += this->data[i] * v.data[i];
	return result;
}

int Vector::getSize() const
{
	return this->n;
}

void Vector::print()
{
	for (int i = 0; i < n; i++)
	{
		std::cout << this->data[i] << " ";
	}
	std::cout << std::endl;
}

void Vector::print(int i)
{
	std::cout << data[i] << std::endl;
}

void Vector::popBack()
{
	this->n = this->n - 1;
}

bool Vector::isNull()
{
	int ans = 1;
	for (int i = 0; i < this->n; i++) {
		if (abs(this->data[i]) > 1e-6)
			ans = 0;
	}
	return ans;
}

bool Vector::isConjoint()
{
	bool a = 0;
	for (int i = 0; i < this->n - 1; i++) {
		if (abs(this->data[i]) > 1e-6) {
			a = 1;
		}
	}
	if (abs(this->data[this->n - 1]) > 1e-6 && a == 0) {
		return false;
	}
	return true;
}


double& Vector::operator[](int i)
{
	return data[i];
}

double Vector::operator[](int i) const
{
	return data[i];
}

Vector operator*(double d, const Vector& m)
{
	return m * d;
}

std::ostream& operator<<(std::ostream& out, const Vector& v)
{
	for (int i = 0; i < v.n; i++)
		out << v.data[i] << " ";
	return out;
}

std::istream& operator>>(std::istream& in, const Vector& v)
{
	for (int i = 0; i < v.n; i++)
		in >> v.data[i];
	return in;
}