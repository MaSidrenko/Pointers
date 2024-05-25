#include<iostream>

using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
template<typename T>T** Allocate(const int rows, const int cols);
template<typename T>void Clear(T** arr, const int rows);

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(double arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(char arr[], const int n, int minRand = 0, int maxRand = 100);

void FillRand(int** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
void FillRand(double** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
void FillRand(char** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);

template<typename T>void Print(T arr[], const int n);
template<typename T>void Print(T** arr, const int rows, const int cols);

template<typename T>void Push_Col_Back(T** arr, const int rows, int& cols);
template<typename T>void Push_Col_Front(T** arr, const int rows, int& cols);

template<typename T>T* Push_Back(T arr[], int& n, const T value);
template<typename T>T* Push_Front(T arr[], int& n, T value);

template<typename T>T** Push_Row_Back(T** arr, int& rows, const int cols);
template<typename T>T** Push_Row_Front(T** arr, int& rows, const int cols);

template<typename T>T* Insert(T arr[], int& n, T value, int index);
template<typename T>T** Insert_Row(T** arr, int& rows, const int cols, int index);
template<typename T>void Insert_Col(T** arr, const int rows, int& cols, int index);

template<typename T>T* Erase(T arr[], int& n, int index);
template<typename T>T** Erase_Row(T** arr, int& rows, const int cols, int index);
template<typename T>void Erase_Col(T** arr, const int rows, int& cols, int index);

template<typename T>T* Pop_Back(T arr[], int& n);
template<typename T>T* Pop_Front(T arr[], int& n);

template<typename T>T** Pop_Row_Back(T** arr, int& rows, const int cols);
template<typename T>T** Pop_Row_Front(T** arr, int& rows, const int cols);

template<typename T>void Pop_Col_Back(T** arr, const int rows, int& cols);
template<typename T>void Pop_Col_Front(T** arr, const int rows, int& cols);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");
	typedef double DataType;
	int index;
#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "Введите длинну массива: "; cin >> n;
	DataType* arr = new DataType[n];
	FillRand(arr, n);
	Print(arr, n);

	DataType value;
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
	cout << "Значение удалено по индексу " << index << " массива: "; arr = Erase(arr, n, index);
	Print(arr, n);
	delete[] arr;
#endif // DYNAMIC_MEMORY_1


#ifdef DYNAMIC_MEMORY_2
	int rows;
	int cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строк: "; cin >> cols;
	DataType** arr = Allocate<DataType>(rows, cols);

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	arr = Push_Row_Back(arr, rows, cols);
	cout << "Строка добавлена в конец массива: " << endl;
	Print(arr, rows, cols);

	arr = Push_Row_Front(arr, rows, cols);
	cout << "Строка добавлена в начало массива: " << endl;
	Print(arr, rows, cols);

	cout << "Введите индекс добавляемой строки: "; cin >> index;
	arr = Insert_Row(arr, rows, cols, index);
	cout << "Строка добавлена по индексу " << index << " в массив: " << endl;
	Print(arr, rows, cols);

	cout << "Строка удалена из конца массива: " << endl;
	arr = Pop_Row_Back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Строка удалена из начала массива: " << endl;
	arr = Pop_Row_Front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Введите индекс удаляемой строки: "; cin >> index;
	arr = Erase_Row(arr, rows, cols, index);
	cout << "Строка удалена по индексу " << index << " из массива: " << endl;
	Print(arr, rows, cols);
	
	cout << "Столбец добавлен в начало массива: " << endl;
	Push_Col_Front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Столбец добавлен в конец массива: " << endl;
	Push_Col_Back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Введите индекс добавляемого столбца: "; cin >> index;
	Insert_Col(arr, rows, cols, index);
	cout << "Столбец добавлен по индексу " << index << " в массив: " << endl;
	Print(arr, rows, cols);
	
	cout << "Столбец удален из начала массива: " << endl;
	Pop_Col_Back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Столбец удален из конца массива: " << endl;
	Pop_Col_Front(arr, rows, cols);
	Print(arr, rows, cols);
	
	cout << "Введите индекс удаляемого столбца: "; cin >> index;
	Erase_Col(arr, rows, cols, index);
	cout << "Столбец удален по индексу " << index << " из массива: " << endl;
	Print(arr, rows, cols);

	Clear(arr, rows);
#endif // DYNAMIC_MEMORY_2

}
template<typename T>T** Allocate(const int rows, const int cols)
{
	T** arr = new T* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T[cols];
	}
	return arr;
}
template<typename T>void Clear(T** arr, const int rows)
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
	minRand *= 100;
	maxRand *= 100;
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % (maxRand - minRand) + maxRand;
		*(arr + i) /= 100;
	}
}
void FillRand(char arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand();
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
	minRand *= 100;
	maxRand *= 100;
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
template<typename T>void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}
template<typename T>void Print(T** arr, const int rows, const int cols)
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

template <typename T>T* Push_Back(T arr[], int& n, const T value)
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
template<typename T>T** Push_Row_Back(T** arr, int& rows, const int cols)
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
template<typename T>void Push_Col_Back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buff_arr = new T[cols + 1];
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
template<typename T>T* Push_Front(T arr[], int& n, T value)
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
template<typename T>T** Push_Row_Front(T** arr, int& rows, const int cols)
{
	T** buff_arr = new T* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		buff_arr[i + 1] = arr[i];
	}
	delete[] arr;
	buff_arr[0] = new T[cols] {};
	rows++;
	return buff_arr;
}
template<typename T>void Push_Col_Front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
	T* buff_arr = new T [cols + 1];
		for (int j = 0; j < cols; j++) {
			buff_arr[j + 1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buff_arr;
		arr[i][0] = {  };
	}
	cols++;
}
template<typename T>T* Insert(T arr[], int& n, T value, int index)
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
template<typename T>T** Insert_Row(T** arr, int& rows, const int cols, int index)
{
	if (index >= rows)return arr;
	T** buff_arr = new T* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		buff_arr[i < index ? i : i + 1] = arr[i];
	}
	delete[] arr;
	arr = buff_arr;
	arr[index] = new T[cols] {};
	rows++;
	return arr;
}
template<typename T>void Insert_Col(T** arr, const int rows, int& cols, int index)
{
	if (index >= cols) return;
	for (int i = 0; i < rows; i++)
	{
		T* buff_arr = new T[cols + 1];
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
template<typename T>T* Erase(T arr[], int& n, int index)
{
	T* buff_arr = new T[--n];
	for (int i = 0; i < n; i++)
	{
		buff_arr[i] = arr[i < index ? i : i + 1];
	}
	delete[] arr;
	return buff_arr;
}
template<typename T>T** Erase_Row(T** arr, int& rows, const int cols, int index)
{
	T** buff_arr = new T*[--rows];
	for (int i = 0; i < rows; i++)
	{
		buff_arr[i] = arr[i < index ? i : i + 1];
	}
	delete[] arr[index];
	delete[] arr;
	return buff_arr;
}
template<typename T>void Erase_Col(T** arr, const int rows, int& cols, int index)
{
	for (int i = 0; i < rows; i++)
	{
		T* buff_arr = new T [cols - 1];
		for (int j = 0; j < cols - 1; j++)
		{
			buff_arr[j] = arr[i][j < index ? j : j + 1];
		}
		delete[] arr[i];
		arr[i] = buff_arr;
	}
	cols--;
}
template<typename T>T* Pop_Back(T arr[], int& n)
{
	T* buff_arr = new T[--n];
	for (int i = 0; i < n; i++)
	{
		buff_arr[i] = arr[i];
	}
	delete[] arr;
	return buff_arr;
}
template<typename T>T** Pop_Row_Back(T** arr, int& rows, const int cols)
{
	T** buff_arr = new T* [--rows];
	for (int i = 0; i < rows; i++)
	{
		buff_arr[i] = arr[i];
	}
	delete[] arr[rows];
	delete[] arr;
	return buff_arr;
}
template<typename T>void Pop_Col_Back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buff_arr = new T[cols];
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
template<typename T>T** Pop_Row_Front(T** arr, int& rows, const int cols)
{
	T** buff_arr = new T* [--rows];
	for (int i = 0; i < rows; i++)
	{
		buff_arr[i] = arr[i + 1];
	}
	delete[] arr[0];
	delete[] arr;
	return buff_arr;
}
template<typename T>void Pop_Col_Front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buff_arr = new T[cols];
		for (int j = 0; j < cols; j++)
		{
			buff_arr[j] = arr[i][j + 1];
		}
		delete[] arr[i];
		arr[i] = buff_arr;
	}
	cols--;
}