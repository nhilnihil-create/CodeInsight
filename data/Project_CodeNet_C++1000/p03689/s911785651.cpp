#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int MaxN = 500;
const int MaxM = 500;

int n, m, h, w;

int mark[MaxN];

int main()
{
	ios::sync_with_stdio(false);

	cin >> n >> m >> h >> w;

	if (n % h == 0 && m % w == 0)
	{
		cout << "No" << endl;
		return 0;
	}

	cout << "Yes" << endl;

	if (n % h != 0)
	{
		for (int i = 0; i < n; ++i)
			mark[i] = -1000;
		for (int i = 0; i < n; i += h)
			mark[i] = 1000 * (h - 1) - 1;

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
				cout << mark[i] << ' ';
			cout << endl;
		}
	}
	else
	{
		for (int i = 0; i < m; ++i)
			mark[i] = -1000;
		for (int i = 0; i < m; i += w)
			mark[i] = 1000 * (w - 1) - 1;

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
				cout << mark[j] << ' ';
			cout << endl;
		}
	}

	return 0;
}