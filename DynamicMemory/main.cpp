#include<iostream>

using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
int* Push_Back(int arr[], int& n, int value);






void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "������� ����������� �������: "; cin >> value;
	arr = Push_Back(arr, n, value);
	Print(arr, n);
	delete[] arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}
int* Push_Back(int arr[], int& n, int value)
{
	int* buff_arr = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buff_arr[i] = arr[i];
	}
	delete[] arr;
	arr = buff_arr;
	arr[n] = value;
	n++;
	return arr;
}


