#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<stdio.h>
#include<queue>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	vector<string>name(a);

	for (int i = 0; i < a; i++)
	{
		cin >> name[i];
	}

	sort(name.begin(), name.end());

	string x = "";

	for (int i = 0; i < a; i++)
	{
		x = x + name[i];
	}

	cout << x << endl;

}

