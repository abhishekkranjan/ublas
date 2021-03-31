#include "matrix.h"
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	//First Matrix declaration
	Matrix A(3, 3);
	cin >> A;
	cout << A << "\n";
	//Second Matrix declaration
	Matrix B(3, 3);
	cin >> B;
	cout << B << "\n";
	cout << (A == B) << "\n";  //Check whether A and B are equal
	cout << (A != B) << "\n";  //Check whether A and B are not equal
	cout << (A + B) << "\n";   //Print the sum of A and B
	cout << (A - B) << "\n";   //Print the difference of A and B
	cout << (A * B) << "\n";   //Print the product of A and B

	//Declaration of third Matrix directly by reference of First Matrix
	Matrix C = A.Transpose();
	cout << C << "\n";         //Print C= Transpose of A
	return 0;
}