#include <bits/stdc++.h>
using namespace std;
int uni[100000]; 
int root(int a)
{
	if (uni[a] < 0) return a;
	return uni[a] = root(uni[a]);
}

bool connect(int a, int b)
{
	a = root(a);
	b = root(b);
	if (a == b) return false;
	if (uni[a] > uni[b])
	{
		a ^= b;
		b ^= a;
		a ^= b;
	}
	uni[a] = uni[a] + uni[b];
	uni[b] = a;
	return true;
}

bool isConnect(int a, int b)
{
	return root(a) == root(b);
}

int size(int a)
{
	return -uni[root(a)];
}

signed main(void)
{
	int x, y;
	cin >> x >> y;
	uni[1] = -7;
	uni[2] = -1;
	uni[3] = 1;
	uni[4] = -4;
	uni[5] = 1;
	uni[6] = 4;
	uni[7] = 1;
	uni[8] = 1;
	uni[9] = 4;
	uni[10] = 1;
	uni[11] = 4;
	uni[12] = 1;
	if (isConnect(x, y))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}
