#include<iostream>

using std::cout;
using std::cin;
using std::endl;


void Fill_Rand(int arr[], const int SIZE);
void Print(int arr[], const int SIZE);
void even(int arr[], const int SIZE);
void odd(int arr[], const int SIZE);
#define tab "\t"

void main()
{
	setlocale(LC_ALL, "");
	int SIZE = 10;
	int* arr = new int [SIZE];
	int* err = new int[SIZE];
	int* orr = new int[SIZE];
	Fill_Rand(arr, SIZE);
	Print(arr, SIZE);
	cout << "Четные числа: "; even(arr, SIZE);
	cout << "Нёчетные числа: "; odd(arr, SIZE);
	delete[] err, arr, odd;
}
void Fill_Rand(int arr[], const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
void Print(int arr[], const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}
void even(int arr[], const int SIZE)
{
	int count_even = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (arr[i] % 2 == 0)
		{
			count_even++;
			int* err = new int[count_even];
			err[count_even] = arr[i];
			cout << err[count_even] << tab;
		}
	}
	cout << endl;
}
void odd(int arr[], const int SIZE)
{
	int count_odd = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (arr[i] % 2 != 0)
		{
			count_odd++;
			int* orr = new int[count_odd];
			orr[count_odd] = arr[i];
			cout << orr[count_odd] << tab;
		}
	}
	cout << endl;
}