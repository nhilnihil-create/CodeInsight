#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;


int main()
{
	int n, m;
	cin >> n >> m;
	int d[n][n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			d[i][j] = 0;
	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		d[a-1][b-1] += 1;
		d[b-1][a-1] += 1;
	}

	for (int i = 0; i < n; i++)
	{
		int c = 0;
		for (int j = 0; j < n; j++)
			c += d[i][j];
		cout << c << endl;
	}
}

