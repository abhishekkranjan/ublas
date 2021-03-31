#include "vector.h"
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	Vector<int> v;
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	v.push_back(9);
	v.push_back(10);
	v.push_back(11);
	v.push_back(12);

	// iterator for traversal in vector v
	Vector<int>::iterator it;

	// Function called to display element in vector in v
	cout << "Element in vector v : ";
	display(v);

	// Print the size of vector v
	cout << "size: " << v.size() << endl;

	// Print Element at index 2
	cout << "v[2]: " << v[2] << '\n';

	// Pop an element and print it
	cout << "Popped Element: " << v.pop_back() << '\n';
	display(v);

	cout << endl;

	cout << "For Char data_type" << endl;

	Vector<char> c;
	c.push_back('a');
	c.push_back('b');
	c.push_back('c');
	c.push_back('d');
	c.push_back('e');
	c.push_back('f');
	c.push_back('g');
	c.push_back('h');

	// Declare iterator for traversal in vector c
	Vector<char>::iterator it1;

	// Function called to display element in vector c
	cout << "Element in vector c : ";
	display(c);

	// Print the size of vector c
	cout << "size: " << c.size() << '\n';

	// Print Element at index 2
	cout << "c[2]: " << c[2] << '\n';

	// Pop an element and print it
	cout << "pop: " << c.pop_back() << '\n';

	// Function called to display element in vector c
	cout << "Element in vector c : ";
	display(c);
	return 0;
}
