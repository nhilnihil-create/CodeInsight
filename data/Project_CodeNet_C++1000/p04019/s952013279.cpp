#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 1000+20
int ans[4];
int main()
{
	string a;
	cin >> a;
	int len = a.length(),flag = 0;
	for (int i = 0; i < len; i++)
	{
		if (a[i] == 'N') ans[0] = 1;
		if (a[i] == 'S') ans[1] = 1;
		if (a[i] == 'W') ans[2] = 1;
		if (a[i] == 'E') ans[3] = 1;
	}
	if (ans[0] && ans[1] && ans[2] && ans[3]) flag = 1;
	if (ans[0] && ans[1] && !ans[2] && !ans[3]) flag = 1;
	if (!ans[0] && !ans[1] && ans[2] && ans[3]) flag = 1;
	if (flag) 
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}