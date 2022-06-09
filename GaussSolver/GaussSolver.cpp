#include "GaussSolver.h"
#include"Matrix.h"
#include"Vector.h"
#include<vector>
#include<iostream>



std::vector<Vector> GaussSolver::solve(const Matrix& A, const Vector& b)
{
	
	std::vector < double > a(A.getColumns());

	std::vector<Vector> ans(A.getColumns());

	std::vector <double> copy(b.getSize());
		
	for (int i = 0; i < b.getSize(); i++)
		copy[i] = b[i];

	//for (int i = 0; i < b.getSize(); i++) { //копия вектора значений 
	//	copy[i] = b[i];
	//}

	std::vector< std::vector<double> > copyA(A.getLines(), std::vector<double> (A.getColumns()));


	for (int i = 0; i < A.getLines(); i++) { // копия матрицы 
		for (int j = 0; j < A.getColumns(); j++)
			copyA[i][j] = (double)A[i][j];
	}
	
	//std::cout << "test:";

	//std::cout << "Before: A[" << 1 << "][" << 1 << "] = " << copyA[1][1] << std::endl; 
	//copyA[1][1] -= copyA[0][1]; // формула (2)
	//std::cout << "After: A[" << 1 << "][" << 1 << "] = " << copyA[1][1] << std::endl;
	int d;
	//std::cout << "test:";
	for (int k = 0; k < A.getLines(); k++){ // прямой ход

		for (int j = k + 1; j < A.getLines(); j++){

			d = copyA[j][k] / copyA[k][k]; // формула (1)


			for (int i = k; i < A.getLines(); i++){

				copyA[j][i] -= d * copyA[k][i]; // формула (2)

			}

			copy[j] -= d * copy[k]; // формула (3)

		}

	}

	std::cout << "test output:" << std::endl;
	
	for (int i = 0; i < A.getLines(); i++){  //output

		std::cout << std::endl;
		for (int j = 0; j < A.getLines(); j++){
	
			std::cout << copyA[i][j] << "   ";
	
	
		}
	
	
	}

	//std::vector<double> s(A.getColumns());
	double s = 0;

	for (int k = A.getLines() - 1; k >= 0; k--){ // обратный ход


		d = 0;

		for (int j = k + 1; j < A.getLines(); j++){

			s = copyA[k][j] * a[j]; // формула (4)

			d = d + s; // формула (4)

		}

		ans[k] = (copy[k] - d) / A[k][k]; // формула (4)

	}

//	for (int i = 0; i < A.getLines(); i++)
//
//		std::cout << "x[" << i << "]=" << ans[i] << " " << std::endl;

	return ans;

}
