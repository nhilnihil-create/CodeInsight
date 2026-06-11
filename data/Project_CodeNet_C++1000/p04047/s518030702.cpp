// stvorec.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int i, int j)
{
	return i > j;
}
int main()
{
	int n;
	cin >> n;
	int *pole = new int[2*n];
	for (int i = 0; i < n*2; i++)
	{
		cin >> pole[i];
	}
	sort(pole, pole + 2*n, cmp);
		int dokopy = 0;
	for (int i = 0; i < n*2; i = i + 2)
	{
		dokopy = dokopy + min(pole[i], pole[i + 1]);
	}
	cout << dokopy << endl;
    return 0;
}

