// C++ header file to implement Custom Matrix class
#include<iostream>
#include<fstream>
using namespace std;


class Matrix
{
private:
	//variables to store no of rows and columns in the matrix
	int rows, cols;
	//pointer for original matrix
	int* pMatrix;
public:
	Matrix(int Rows, int Cols)
	{
		rows = Rows;
		cols = Cols;

		pMatrix = new int[rows * cols];
	}
	Matrix(int size)
	{
		rows = size;
		cols = size;
		pMatrix = new int[rows * cols];
	}
	Matrix(const Matrix& matrix)
	{
		rows = matrix.rows;
		cols = matrix.cols;

		pMatrix = new int[rows * cols];
		for (int i = 0; i < rows * cols; i++)
		{
			pMatrix[i] = matrix.pMatrix[i];
		}
	}
	~Matrix()
	{
		delete []pMatrix;
	}
	//Assign operator overloading
	Matrix& operator =(const Matrix& matrix)
	{
		this->~Matrix();

		rows = matrix.rows;
		cols = matrix.cols;

		pMatrix = new int[rows * cols];
		for (int i = 0; i < rows * cols; i++)
		{
			pMatrix[i] = matrix.pMatrix[i];
		}
		return *this;
	}
	// Equal operator overloading
	bool operator== (const Matrix& matrix)
	{
		if (rows == matrix.rows && cols == matrix.cols)
		{
			for (int i = 0; i < rows * cols; i++)
			{
				if (pMatrix[i] != matrix.pMatrix[i])
				{
					return false;
				}
			}
			return true;
		}
		else
		{
			return false;
		}
	}
	//Not equals operator overloading
	bool operator!= (const Matrix& matrix)
	{
		return 1 - (*this == matrix);
	}
	//Addition operator overloading
	Matrix operator + (const Matrix& matrix)
	{
		if (rows == matrix.rows && cols == matrix.cols)
		{
			Matrix result(rows, cols);
			for (int i = 0; i < rows * cols; i++)
			{
				result.pMatrix[i] = pMatrix[i] + matrix.pMatrix[i];
			}
			return result;
		}
	}
	//Subtraction operator overloading
	Matrix operator - (const Matrix& matrix)
	{
		if (rows == matrix.rows && cols == matrix.cols)
		{
			Matrix result(rows, cols);
			for (int i = 0; i < rows * cols; i++)
			{
				result.pMatrix[i] = pMatrix[i] - matrix.pMatrix[i];
			}
			return result;
		}
	}
	//Multiplication operator overloading
	Matrix operator * (const Matrix& matrix)
	{
		if (cols == matrix.rows)
		{
			Matrix result(rows, matrix.cols);
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < matrix.cols; j++)
				{
					result.pMatrix[i * result.cols + j] = 0;
					for (int k = 0; k < cols; k++)
					{
						result.pMatrix[i * result.cols + j] += pMatrix[i * cols + k] * matrix.pMatrix[k * matrix.cols + j];
					}
				}
			}
			return result;
		}
	}
	//function for transpose of a matrix
	Matrix Transpose()
	{
		Matrix result(cols, rows);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				result.pMatrix[j * rows + i] = pMatrix[i * cols + j];
			}
		}
		return result;
	}
	friend ostream & operator  <<(ostream &out, const Matrix& matrix);
	friend istream & operator >> (istream &in,  Matrix& matrix);
};
//operator overloading for cin
istream& operator>> (istream& in, Matrix&matrix)
{
	for (int i = 0; i < matrix.rows * matrix.cols; i++)
	{
		in >> matrix.pMatrix[i];
	}
	return in;
}
//operator overloading for cout
ostream& operator<<  (ostream& out, const Matrix&matrix)
{
	for (int i = 0; i < matrix.rows; i++)
	{
		for (int j = 0; j < matrix.cols; j++)
		{
			out << matrix.pMatrix[i * matrix.cols + j] << " ";
		}
		out << endl;
	}
	return out;
}
