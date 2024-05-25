#include<iostream>

using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
template<typename T>T** Allocate(const T rows, const T cols);
template<typename T>void Clear(T** arr, const int rows);

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(double arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(char arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
void FillRand(double** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
void FillRand(char** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
template<typename T>void Print(T arr[], const int n);
template<typename T>void Print(T** arr, const int rows, const int cols);


template<typename T>T* Push_Back(T arr[], int& n, T value);
template<typename T>T** Push_Row_Back(T** arr, int& rows, const int cols);
void Push_Col_Back(int** arr, const int rows, int& cols);
template<typename T>T* Push_Front(T arr[], int& n, T value);
int** Push_Row_Front(int** arr, int& rows, const int cols);
void Push_Col_Front(int** arr, const int rows, int& cols);

template<typename T>T* Insert(T arr[], int& n, T value, int index);
int** Insert_Row(int** arr, int& rows, const int cols, int index);
void Insert_Col(int** arr, const int rows, int& cols, int index);
template<typename T>T* Erase(T arr[], int& n, int index);
int** Erase_Row(int** arr, int& rows, const int cols, int index);
void Erase_Col(int** arr, const int rows, int& cols, int index);

template<typename T>T* Pop_Back(T arr[], int& n);
int** Pop_Row_Back(int** arr, int& rows, const int cols);
void Pop_Col_Back(int** arr, const int rows, int& cols);
template<typename T>T* Pop_Front(T arr[], int& n);
int** Pop_Row_Front(int** arr, int& rows, const int cols);
void Pop_Col_Front(int** arr, const int rows, int& cols);

//#define DYNAMIC_MEMORY_1
//#define DYNAMIC_MEMORY_2
//#define DYNAMIC_MEMORY_1_DOUBLE
//#define DYNAMIC_MEMORY_1_CHAR
#define DYNAMIC_MEMORY_2_DOUBLE

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


#ifdef DYNAMIC_MEMORY_2
	int rows;
	int cols;
	int index;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строк: "; cin >> cols;
	int** arr = Allocate(rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	arr = Push_Row_Back(arr, rows, cols);
	Print(arr, rows, cols);
	arr = Push_Row_Front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Введите индекс добавляемой строки: "; cin >> index;
	arr = Insert_Row(arr, rows, cols, index);
	Print(arr, rows, cols);
	arr = Pop_Row_Back(arr, rows, cols);
	Print(arr, rows, cols);
	arr = Pop_Row_Front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Введите индекс удаляемой строки: "; cin >> index;
	arr = Erase_Row(arr, rows, cols, index);
	Print(arr, rows, cols);
	Push_Col_Front(arr, rows, cols);
	Print(arr, rows, cols);
	Push_Col_Back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Введите индекс добавляемого столбца: "; cin >> index;
	Insert_Col(arr, rows, cols, index);
	Print(arr, rows, cols);
	Pop_Col_Back(arr, rows, cols);
	Print(arr, rows, cols);
	Pop_Col_Front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Введите индекс удаляемого столбца: "; cin >> index;
	Erase_Col(arr, rows, cols, index);
	Print(arr, rows, cols);
	Clear(arr, rows);
#endif // DYNAMIC_MEMORY_2

#ifdef DYNAMIC_MEMORY_1_DOUBLE
	double value;
	int d_n, index;
	cout << "Введите размер массива: "; cin >> d_n;
	cout << "Введите добавляемое значение: "; cin >> value;
	double* d_arr = new double[d_n];
	FillRand(d_arr, d_n);
	Print(d_arr, d_n);
	d_arr = Push_Back(d_arr, d_n, value);
	Print(d_arr, d_n);
	d_arr = Push_Front(d_arr, d_n, value);
	Print(d_arr, d_n);
	cout << "Введите индекс: "; cin >> index;
	d_arr = Insert(d_arr, d_n, value, index);
	Print(d_arr, d_n);
	cout << "Введите индекс: "; cin >> index;
	d_arr = Erase(d_arr, d_n, index);
	Print(d_arr, d_n);
	d_arr = Pop_Back(d_arr, d_n);
	Print(d_arr, d_n);
	d_arr = Pop_Front(d_arr, d_n);
	Print(d_arr, d_n);
	delete[] d_arr;
#endif // DYNAMIC_MEMORY_1_DOUBLE

#ifdef DYNAMIC_MEMORY_1_CHAR
	char value;
	int c_n, index;
	cout << "Введите размер массива:"; cin >> c_n;
	cout << "Введите добавляемый символ: "; cin >> value;
	char* c_arr = new char[c_n];
	FillRand(c_arr, c_n);
	Print(c_arr, c_n);
	c_arr = Push_Back(c_arr, c_n, value);
	Print(c_arr, c_n);
	c_arr = Push_Front(c_arr, c_n, value);
	Print(c_arr, c_n);
	cout << "Введиет индекс: "; cin >> index;
	c_arr = Insert(c_arr, c_n, value, index);
	Print(c_arr, c_n);
	cout << "Введиет индекс: "; cin >> index;
	c_arr = Erase(c_arr, c_n, index);
	Print(c_arr, c_n);
	c_arr = Pop_Back(c_arr, c_n);
	Print(c_arr, c_n);
	c_arr = Pop_Front(c_arr, c_n);
	Print(c_arr, c_n);
	delete[] c_arr;
#endif // DYNAMIC_MEMORY_1_CHAR
	
	int d_rows, d_cols;
	int index; 
	cout << "Введите количество строк: "; cin >> d_rows;
	cout << "Введите количество элементов строк: "; cin >> d_cols;
	double** d_arr = Allocate(d_rows,d_cols);
	FillRand(d_arr, d_rows, d_cols);
	Print(d_arr, d_rows, d_cols);
	d_arr = Push_Row_Back(d_arr, d_rows, d_cols);
	Print(d_arr, d_rows, d_cols);
	Clear(d_arr, d_rows);
}
template<typename T>
T** Allocate(const T rows, const T cols)
{
	T** arr = new T* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T[cols];
	}
	return arr;
}
template<typename T>

void Clear(T** arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}
void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % (maxRand - minRand) + maxRand;
	}
}
void FillRand(double arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % (maxRand - minRand) + maxRand;
		arr[i] /= 100;
	}
}
void FillRand(char arr[], const int n, int minRand, int maxRand)
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
void FillRand(double** arr, const int rows, const int cols, int minRand, int maxRand)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % (maxRand - minRand) + minRand;
			arr[i][j] /= 100;
		}
	}
}
void FillRand(char** arr, const int rows, const int cols, int minRand, int maxRand)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % (maxRand - minRand) + minRand;
		}
	}
}
template<typename T>
void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}
template<typename T>
void Print(T** arr, const int rows, const int cols)
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

template <typename T>
T* Push_Back(T arr[], int& n, T value)
{
	T* buff_arr = new T[n + 1];
	for (int i = 0; i < n; i++)
	{
		buff_arr[i] = arr[i];
	}
	delete[] arr;
	buff_arr[n++] = value;
	return buff_arr;
}
template<typename T>
T** Push_Row_Back(T** arr, int& rows, const int cols)
{
	T** buff_arr = new T* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		buff_arr[i] = arr[i];
	}
	delete[] arr;
	buff_arr[rows] = new T[cols] {};
	rows++;
	return buff_arr;
}
void Push_Col_Back(int** arr, const int rows, int& cols)
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
}
template<typename T>
T* Push_Front(T arr[], int& n, T value)
{
	T* buff_arr = new T[n + 1];
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
void Push_Col_Front(int** arr, const int rows, int& cols)
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
}
template<typename T>
T* Insert(T arr[], int& n, T value, int index)
{
	T* buff_arr = new T[n + 1];
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
void Insert_Col(int** arr, const int rows, int& cols, int index)
{
	if (index >= cols) return;
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
}
template<typename T>
T* Erase(T arr[], int& n, int index)
{
	T* buff_arr = new T[--n];
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
void Erase_Col(int** arr, const int rows, int& cols, int index)
{
	for (int i = 0; i < rows; i++)
	{
		int* buff_arr = new int [cols - 1];
		for (int j = 0; j < cols - 1; j++)
		{
			buff_arr[j] = arr[i][j < index ? j : j + 1];
		}
		delete[] arr[i];
		arr[i] = buff_arr;
	}
	cols--;
}
template<typename T>
T* Pop_Back(T arr[], int& n)
{
	T* buff_arr = new T[--n];
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
	delete[] arr[rows];
	delete[] arr;
	return buff_arr;
}
void Pop_Col_Back(int** arr, const int rows, int& cols)
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
}
template<typename T>
T* Pop_Front(T arr[], int& n)
{
	T* buff_arr = new T[--n];
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
void Pop_Col_Front(int** arr, const int rows, int& cols)
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
}
