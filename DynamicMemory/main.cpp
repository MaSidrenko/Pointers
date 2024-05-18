#include<iostream>

using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
int* Push_Back(int arr[], int& n, int value);
int* Push_Front(int arr[], int& n, int value);
int* Insert(int arr[], int& n, int value, int v);
int* Pop_Back(int arr[], int& n);
int* Pop_Front(int arr[], int& n);


void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите длинну массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значени: "; cin >> value;
	int v;
	cin >> v;
	arr = Push_Back(arr, n, value);
	cout << "Значение "<< value << " добавлено в конец массива : "; Print(arr, n);
	arr = Push_Front(arr, n, value);
	cout << "Значение " << value << " добавлено в начало массива : "; Print(arr, n);
	//arr = Insert(arr, n, value, v);
	//Print(arr, n);
	cout << "Значение "<< value << " удалено из конца массива : "; arr = Pop_Back(arr, n);
	Print(arr, n);
	cout << "Значение " << value << " удалено из начала массива : "; arr = Pop_Front(arr, n);
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
int* Push_Front(int arr[], int& n, int value)
{
	int* buff_arr = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buff_arr[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buff_arr;
	arr[0] = value;
	n++;
	return arr;
}
int* Insert(int arr[], int& n, int value, int v)
{
	int* buff_arr = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buff_arr[i] = arr[i];
	}
	delete[] arr;
	arr = buff_arr;
	arr[v] = value;
	n++;
	return arr;
}
int* Pop_Back(int arr[], int& n)
{
	int* buff_arr = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buff_arr[i] = arr[i];
	}
	delete[] arr;
	arr = buff_arr;
	n--;
	return arr;
}
int* Pop_Front(int arr[], int& n)
{
	int* buff_arr = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buff_arr[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buff_arr;
	n--;
	return arr;
}
