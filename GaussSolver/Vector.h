#pragma once
#include <iostream>

class Vector {
private:
	double* data = 0;
	int n = 0;
public:
	Vector();
	Vector(int n);
	void resize(int newSize);
	Vector(const Vector& v);
	~Vector();

	Vector& operator=(const Vector& v);
	Vector operator+(const Vector& v) const;
	Vector& operator+=(const Vector& v);
	Vector operator-(const Vector& v) const;
	Vector& operator-=(const Vector& v);
	Vector operator*(double d) const;
	Vector& operator*=(double d);

	double dot(const Vector& v) const;

	friend Vector operator*(double d, const Vector& m);
	friend std::ostream& operator<<(std::ostream& out, const Vector& v);
	friend std::istream& operator>>(std::istream& in, const Vector& v);

	int getSize() const;
	void print();
	void print(int i);
	void popBack();
	bool isNull();
	bool isConjoint();

	double& operator[](int i);
	double operator[](int i) const;
};