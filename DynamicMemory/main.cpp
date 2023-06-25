#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(const int arr[], const int n);
int* push_back(int arr[], int& n, const int value);

void main()
{
	int n;
	cout << "Enter array size: "; cin >> n;
	int* arr = new int[n];	//arr == 0x100
	cout << &arr << endl;
	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "Input value to append array: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	delete[] arr;	//Memory leak
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void Print(const int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;
}
int* push_back(int arr[], int& n, const int value)	//arr == 0x200
{
	cout << &arr << endl;
	//1) Создаем массив нужного размера:
	int* buffer = new int[n + 1];

	//2) Копируем все значения из исходного массива в буферный:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}

	//3) Удаляем старый массив:
	delete[] arr;

	//4) Подменяем адрес исходного массива адресом нового массива:
	arr = buffer;

	//5) И только после всего этого можно добавить значение в конец массива:
	arr[n] = value;

	//6) После добавления элемента в конец массива, количество его элементов увеличивается на 1:
	n++;

	//7) Зануляем buffer, чтобы небыло двух указателей на одну область памяти:
	buffer = 0;
	return arr;
}
