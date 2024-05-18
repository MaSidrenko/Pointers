#include<iostream>

using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

int* Push_Back(int arr[], int& n, int value);
int* Push_Front(int arr[], int& n, int value);

int* Insert(int arr[], int& n, int value, int index);
int* Erase(int arr[], int& n, int index);

int* Pop_Back(int arr[], int& n);
int* Pop_Front(int arr[], int& n);

#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите длинну массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);

	int value;
	int index;
	cout << "Введите добавляемое значени: "; cin >> value;
	arr = Push_Back(arr, n, value);
	cout << "Значение "<< value << " добавлено в конец массива: "; Print(arr, n);
	
	cout << "Введите добавляемое значени: "; cin >> value;
	arr = Push_Front(arr, n, value);
	cout << "Значение " << value << " добавлено в начало массива: "; Print(arr, n);



	cout << "Значение "<< value << " удалено из конца массива: "; arr = Pop_Back(arr, n);
	Print(arr, n);

	cout << "Значение " << value << " удалено из начала массива: "; arr = Pop_Front(arr, n);
	Print(arr, n);

	cout << "Введите добавляемое значени: "; cin >> value;
	cout << "Введите индекс: "; cin >> index;
	cout << "Значение " << value << " добавлено по индексу " << index << " массива: "; arr = Insert(arr, n, value, index);
	Print(arr, n);

	cout << "Введите индекс: "; cin >> index;
	cout << "Значение " << value << " удалено по индексу " << index << " массива: "; arr = Erase(arr, n, index);
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
	buff_arr[n] = value;
	n++;
	return buff_arr;
}
int* Push_Front(int arr[], int& n, int value)
{
	int* buff_arr = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buff_arr[i + 1] = arr[i];
	}
	delete[] arr;
	buff_arr[0] = value;
	n++;
	return buff_arr;
}
int* Insert(int arr[], int& n, int value, int index)
{
	int* buff_arr = new int[n + 1];
	/*for (int i = 0; i < index; i++)
	{
		buff_arr[i] = arr[i];
		for (int i = index; i < n; i++)
		{
			buff_arr[i + 1] = arr[i];
		}
	}*/
	for (int i = 0; i < n; i++)
	{
		//i < index ? buff_arr[i] = arr[i] : buff_arr[i + 1] = arr[i];
		buff_arr[i < index ? i : i + 1] = arr[i];
	}
	delete[] arr;
	arr = buff_arr;
	arr[index] = value;
	n++;
	return arr;
}
int* Erase(int arr[], int& n, int index)
{
	int* buff_arr = new int[--n];
	for (int i = 0; i < n; i++)
	{
		buff_arr[i] = arr[i < index ? i : i + 1];
	}
	delete[] arr;
	return buff_arr;
}
int* Pop_Back(int arr[], int& n)
{
	int* buff_arr = new int[--n];
	for (int i = 0; i < n; i++)
	{
		buff_arr[i] = arr[i];
	}
	delete[] arr;
	return buff_arr;
}
int* Pop_Front(int arr[], int& n)
{
	int* buff_arr = new int[--n];
	for (int i = 0; i < n; i++)
	{
		buff_arr[i] = arr[i + 1];
	}
	delete[] arr;
	return buff_arr;
}
