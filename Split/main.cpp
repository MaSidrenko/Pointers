#include<iostream>

using std::cout;
using std::cin;
using std::endl;


void Fill_Rand(int arr[], const int SIZE);
void Print(int arr[], const int SIZE);

#define tab "\t"

void main()
{
	setlocale(LC_ALL, "");
	const int SIZE = 10;
	int arr[SIZE];
	int count_even = 0;
	int count_odd = 0;
	Fill_Rand(arr, SIZE);
	Print(arr, SIZE);
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] % 2 == 0 ? count_even++ : count_odd++;
	}
	cout << "Количество четных элементов массива: " << count_even << endl;
	cout << "Количество нечетных элементов массива: " << count_odd << endl;
	int* err = new int[count_even];
	int* orr = new int[count_odd];
	for (int i = 0, j = 0, k = 0; i < SIZE; i++)
	{
		//arr[i] % 2 == 0 ? err[j++] = arr[i] : orr[k++] = arr[i];
		(arr[i] % 2 == 0 ? err[j++] : orr[k++]) = arr[i];
	}
	Print(err, count_even);
	Print(orr, count_odd);

	delete[] orr;
	delete[] err;
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
