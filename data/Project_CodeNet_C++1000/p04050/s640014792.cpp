#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int MaxN = 100000;
const int MaxM = 100;

int n, m;
int a[MaxM + 1];

inline void construct()
{
	int p = 0, q = 0;
	for (int i = 1; i <= m; ++i)
		if (a[i] & 1)
		{
			if (p == 0)
				p = i;
			else if (q == 0)
				q = i;
			else
			{
				cout << "Impossible\n";
				return;
			}
		}

	if (p > 0)
		swap(a[1], a[p]);
	if (q > 0)
		swap(a[m], a[q]);

	for (int i = 1; i <= m; ++i)
		cout << a[i] << ' ';
	cout << endl;

	if (m == 1)
	{
		if (a[1] == 1)
			cout << "1\n1\n";
		else
		{
			cout << "2\n";
			cout << "1 " << a[1] - 1;
			cout << endl;
		}

		return;
	}

	cout << m - (a[m] == 1) << endl;
	cout << a[1] + 1;
	for (int i = 2; i < m; ++i)
		cout << ' ' << a[i];
	if (a[m] > 1)
		cout << ' ' << a[m] - 1;
	cout << endl;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
		cin >> a[i];

	construct();

	return 0;
}