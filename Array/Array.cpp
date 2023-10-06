#include <iostream>
#include "Array.hpp"

using namespace std;

int main()
{
	ArrayA<int> a(3);
	a.Push(3);
	a.Push(25);
	a.Push(36);
	a.Push(56);
	a.Push(89);

	//a.Pop();
	//a.Remove(2);

	cout << "Contents: ";
	for (int i = 0; i < a.GetSize(); i++)
		cout << a[i] << endl;

	cout << endl;

	cout << "search 56: ";
	cout << a.Search(56);
}

