#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int t[100], all = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> t[i];
		all += t[i];
	}
	int m;
	cin >> m;
	int p[100], x[100];
	for (int i = 0; i < m; ++i)
	{
		cin >> p[i] >> x[i];
		--p[i];
	}
	for (int i = 0; i < m; ++i)
	{
		cout << all - t[p[i]] + x[i] << endl;
	}
	return 0;
}