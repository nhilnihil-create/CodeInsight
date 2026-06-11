#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<stdio.h>
#include<queue>
using namespace std;

int main()
{
	string a;
	cin >> a;
	int size_a;
	size_a = a.length();
	string b = "";

	for (int i = 0; i < size_a; i++)
	{
		if (a[i] == '0')
		{
			b.push_back('0');
		}
		else if (a[i] == '1')
		{
			b.push_back('1');
		}
		else if (a[i]!='0' && a[i]!='1' &&b.length()>0)
		{
			b.pop_back();
		}
	}

	cout << b << endl;

}

