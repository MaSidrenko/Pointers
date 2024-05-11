#include<iostream>

using std::cout;
using std::cin;
using std::endl;

void Exchange(int a, int b);
#define tab "\t"

void main()
{
	setlocale(LC_ALL, "");
	int a = 2, b = 3;
	cout << a << tab << b << endl;
	cout << &a << tab << &b << endl;
	Exchange(a, b);
	cout << a << tab << b << endl;
}

void Exchange(int a, int b)
{
	cout << &a << tab << &b << endl;
	int buffer = a;
	a = b;
	b = buffer;
}