#include<iostream>
using namespace std;

void main()
{
	int a = 2;
	int& ra = a;
	ra += 3;
	cout << a << endl;
}