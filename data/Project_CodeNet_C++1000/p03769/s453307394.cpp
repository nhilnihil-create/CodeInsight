#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
long long n;
int m, i, j, k, l, r, z, a[405], len;
int po[80];
int main()
{
	cin >> n;
	if (n == 1) {cout << "2\n 1 1"; return 0;}
	n ++;
	l = 200; r = 199;
	while (n != 1)
	{
		++len;
		if (n & 1) po[len] = 1;
		n >>= 1;
	}
	//cout << len << endl;
	for(i = len; i >= 1; i --)
	{
		a[++r] = ++z;
		if (po[i]) a[--l] = ++z;
	}
	cout << (r - l + 1) * 2 << endl;
	for(i = l; i <= r; i ++)
		cout << a[i] << " ";
	for(i = 1; i <= r - l + 1; i ++)
		cout << i << " ";
}