#include<iostream>
#include<map>
#include<algorithm>
#include<string>
#include<cmath>
#include<memory.h>
#define pii pair<int,int>
using namespace std;
const int Max = 1e6 + 5;
int lst[Max];
int book[Max];
pii b[Max];

int main()
{
	string a, b, c;
	cin >> a >> b >> c;
	int a1=0, b1=-1, c1 = -1;
	char sec=a[0];
	while (1)
	{
		if (sec == 'a')
		{
			if (a1 == a.size()-1) { cout << "A";break; }
			sec = a[++a1];
		}
		else if (sec == 'b')
		{
			if (b1 == b.size()-1) { cout << "B";break; }
			sec = b[++b1];
		}
		else if (sec == 'c')
		{
			if (c1 == c.size()-1) { cout << "C";break; }
			sec = c[++c1];
		}
	}
}