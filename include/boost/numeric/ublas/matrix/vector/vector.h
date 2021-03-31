// C++ header file to implement Custom Vector class
#include "iostream"
#define ll long long
using namespace std;

// Template class to create vector of different data type
template <typename T>
class Vector {
private:
	T* arr;
	// Variable to store the current capacity of the vector
	ll capacity;
	// Variable to store the length of the vector
	ll length;

public:
	explicit Vector(ll = 100);

	// Function that returns the number of elements in array after pushing the data
	ll push_back(T);

	// function that returns the popped element
	T pop_back();

	// Function that return the size of vector
	ll size() const;
	T& operator[](ll);

	// Iterator Class
	class iterator {
	private:
		// Dynamic array using pointers
		T* ptr;

	public:
		explicit iterator()
			: ptr(nullptr)
		{
		}
		explicit iterator(T* p)
			: ptr(p)
		{
		}
		bool operator==(const iterator& rhs) const
		{
			return ptr == rhs.ptr;
		}
		bool operator!=(const iterator& rhs) const
		{
			return !(*this == rhs);
		}
		T operator*() const
		{
			return *ptr;
		}
		iterator& operator++()
		{
			++ptr;
			return *this;
		}
		iterator operator++(int)
		{
			iterator temp(*this);
			++*this;
			return temp;
		}
	};

	// Begin iterator
	iterator begin() const;

	// End iterator
	iterator end() const;
};

// Template class to return the size of vector of different data type
template <typename T>
Vector<T>::Vector(ll n)
	: capacity(n), arr(new T[n]), length(0)
{
}

// Template class to insert the element in vector
template <typename T>
ll Vector<T>::push_back(T data)
{
	if (length == capacity) {
		T* old = arr;
		arr = new T[capacity = capacity * 2];
		copy(old, old + length, arr);
		delete[] old;
	}
	arr[length++] = data;
	return length;
}

// Template class to return the popped element in vector
template <typename T>
T Vector<T>::pop_back()
{
	return arr[length-- - 1];
}

// Template class to return the size of vector
template <typename T>
ll Vector<T>::size() const
{
	return length;
}

// Template class to return the element of vector at given index
template <typename T>
T& Vector<T>::operator[](ll index)
{
	// if given index is greator than the size of vector print error
	if (index >= length) {
		cout << "Error: Array index out of bound";
		exit(0);
	}

	// else return value at that index
	return *(arr + index);
}

// Template class to return begin iterator
template <typename T>
typename Vector<T>::iterator
Vector<T>::begin() const
{
	return iterator(arr);
}

// Template class to return end iterator
template <typename T>
typename Vector<T>::iterator
Vector<T>::end() const
{
	return iterator(arr + length);
}

// Template class to display element in vector
template <typename V>
void display(V& v)
{
	// Declare iterator
	typename V::iterator ptr;
	for (ptr = v.begin(); ptr != v.end(); ptr++) {
		cout << *ptr << ' ';
	}
	cout << '\n';
}