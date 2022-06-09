#include"Matrix.h"
#include"Vector.h"
#include"GaussSolver.h"
#include<iostream>

int main() {
	int m, n;
	std::cout << "enter dimensions of the Matrix ";
	std::cin >> m ;
	n = m;
	std::cout << std::endl;

	std::cout << "input coeff";

	Matrix A(m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			std::cin >> A[i][j];
	}
	std::cout << "matrix a:" << std::endl;
	A.printM();

	Vector b(m);
	for (int i = 0; i < m; i++) {
		std::cin >> b[i];
	}
	std::cout << "vector b:" << std::endl;
	b.print();
	std::cout << std::endl;


	GaussSolver solver;


	std::vector<Vector> res = solver.solve(A, b);

	std::cout << "result:" << std::endl;
	for (int i = 0; i < res.size(); i++) {
		std::cout << res[i] << std::endl;
	}
	return 0;
}

