#pragma once
#include"Vector.h"
#include"Matrix.h"
#include<vector>
#include<iostream>

class GaussSolver {
public:
	std::vector<Vector> solve(const Matrix& A, const Vector& b);

};