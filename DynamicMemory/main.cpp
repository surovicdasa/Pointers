#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(const int arr[], const int n);

void main()
{
	int n;
	cout << "Enter array size: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	delete[] arr;
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
		cout << *(arr+i) << "\t";
	}
	cout << endl;
}

