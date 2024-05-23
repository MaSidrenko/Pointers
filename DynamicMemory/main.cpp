#include<iostream>

using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
int** Allocate(const int rows, const int cols);
void Clear(int** arr, const int rows);

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);


int* Push_Back(int arr[], int& n, int value);
int** Push_Row_Back(int** arr, int& rows, const int cols);
int** Push_Col_Back(int** arr, const int rows, int& cols);
int* Push_Front(int arr[], int& n, int value);
int** Push_Row_Front(int** arr, int& rows, const int cols);
int** Push_Col_Front(int** arr, const int rows, int& cols);

int* Insert(int arr[], int& n, int value, int index);
int** Insert_Row(int** arr, int& rows, const int cols, int index);
int** Insert_Col(int** arr, const int rows, int& cols, int index);
int* Erase(int arr[], int& n, int index);
int** Erase_Row(int** arr, int& rows, const int cols, int index);

int* Pop_Back(int arr[], int& n);
int** Pop_Row_Back(int** arr, int& rows, const int cols);
int** Pop_Col_Back(int** arr, const int rows, int& cols);
int* Pop_Front(int arr[], int& n);
int** Pop_Row_Front(int** arr, int& rows, const int cols);
int** Pop_Col_Front(int** arr, const int rows, int& cols);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "Введите длинну массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);

	int value;
	int index;
	cout << "Введите добавляемое значени: "; cin >> value;
	arr = Push_Back(arr, n, value);
	cout << "Значение " << value << " добавлено в конец массива: "; Print(arr, n);

	cout << "Введите добавляемое значени: "; cin >> value;
	arr = Push_Front(arr, n, value);
	cout << "Значение " << value << " добавлено в начало массива: "; Print(arr, n);



	cout << "Значение " << value << " удалено из конца массива: "; arr = Pop_Back(arr, n);
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
#endif // DYNAMIC_MEMORY_1
	int rows;
	int cols;
	int index;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строк: "; cin >> cols;
	cin >> index;
	int** arr = Allocate(rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	//arr = Push_Row_Back(arr, rows, cols);
	//Print(arr, rows, cols);
	//arr = Push_Row_Front(arr, rows, cols);
	//Print(arr, rows, cols);
	//arr = Insert_Row(arr, rows, cols, index);
	//Print(arr, rows, cols);
	//arr = Pop_Row_Back(arr, rows, cols);
	//Print(arr, rows, cols);
	//arr = Pop_Row_Front(arr, rows, cols);
	//Print(arr, rows, cols);
	//arr = Erase_Row(arr, rows, cols, index);
	//Print(arr, rows, cols);
	arr = Push_Col_Front(arr, rows, cols);
	Print(arr, rows, cols);
	arr = Push_Col_Back(arr, rows, cols);
	Print(arr, rows, cols);
	arr = Insert_Col(arr, rows, cols, index);
	Print(arr, rows, cols);
	arr = Pop_Col_Back(arr, rows, cols);
	Print(arr, rows, cols);
	arr = Pop_Col_Front(arr, rows, cols);
	Print(arr, rows, cols);
	Clear(arr, rows);
}

void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % (maxRand - minRand) + maxRand;
	}
}
void FillRand(int** arr, const int rows, const int cols, int minRand, int maxRand)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % (maxRand - minRand) + minRand;
		}
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
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
		cout << endl;
}

int** Allocate(const int rows, const int cols)
{
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	return arr;
}

void Clear(int** arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
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
int** Push_Row_Back(int** arr, int& rows, const int cols)
{
	int** buff_arr = new int* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		buff_arr[i] = arr[i];
	}
	delete[] arr;
	buff_arr[rows] = new int[cols] {};
	rows++;
	return buff_arr;
}
int** Push_Col_Back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buff_arr = new int[cols + 1];
		for (int j = 0; j < cols; j++)
		{
		buff_arr[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buff_arr;
		arr[i][cols] = {};
	}
	cols++;
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
	buff_arr[0] = value;
	n++;
	return buff_arr;
}
int** Push_Row_Front(int** arr, int& rows, const int cols)
{
	int** buff_arr = new int* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		buff_arr[i + 1] = arr[i];
	}
	delete[] arr;
	buff_arr[0] = new int[cols] {};
	rows++;
	return buff_arr;
}
int** Push_Col_Front(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
	int* buff_arr = new int [cols + 1];
		for (int j = 0; j < cols; j++) {
			buff_arr[j + 1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buff_arr;
		arr[i][0] = {  };
	}
	cols++;
	return arr;
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
int** Insert_Row(int** arr, int& rows, const int cols, int index)
{
	if (index >= rows)return arr;
	int** buff_arr = new int* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		buff_arr[i < index ? i : i + 1] = arr[i];
	}
	delete[] arr;
	arr = buff_arr;
	arr[index] = new int[cols] {};
	rows++;
	return arr;
}
int** Insert_Col(int** arr, const int rows, int& cols, int index)
{
	if (index >= cols)return arr;
	for (int i = 0; i < rows; i++)
	{
		int* buff_arr = new int[cols + 1];
		for (int j = 0; j < cols; j++)
		{
			buff_arr[j < index ? j : j + 1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buff_arr;
		arr[i][index] = {};
	}
	cols++;
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
int** Erase_Row(int** arr, int& rows, const int cols, int index)
{
	int** buff_arr = new int*[--rows];
	for (int i = 0; i < rows; i++)
	{
		buff_arr[i] = arr[i < index ? i : i + 1];
	}
	delete[] arr[index];
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
int** Pop_Row_Back(int** arr, int& rows, const int cols)
{
	int** buff_arr = new int* [--rows];
	for (int i = 0; i < rows; i++)
	{
		buff_arr[i] = arr[i];
	}
	delete[] arr [rows];
	delete[] arr;
	return buff_arr;
}
int** Pop_Col_Back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buff_arr = new int[cols];
		for (int j = 0; j < cols; j++)
		{
			buff_arr[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buff_arr;
	}
	cols--;
	return arr;
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
int** Pop_Row_Front(int** arr, int& rows, const int cols)
{
	int** buff_arr = new int* [--rows];
	for (int i = 0; i < rows; i++)
	{
		buff_arr[i] = arr[i + 1];
	}
	delete[] arr[0];
	delete[] arr;
	return buff_arr;
}
int** Pop_Col_Front(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buff_arr = new int[cols];
		for (int j = 0; j < cols; j++)
		{
			buff_arr[j] = arr[i][j + 1];
		}
		delete[] arr[i];
		arr[i] = buff_arr;
	}
	cols--;
	return arr;
}
