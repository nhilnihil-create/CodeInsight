#include<bits/stdc++.h>
using namespace std;
int n, m, l[307][307], pos[307], tot[307], res;
bool is[307];
int read()
{
	int num = 0;
	char c = getchar();
	while (c < '0' || c>'9')c = getchar();
	while (c >= '0' && c <= '9')num = num * 10 + c - '0', c = getchar();
	return num;
}
int main()
{
	n = read();
	m = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			l[i][j] = read();
	is[0] = 1;
	res = n;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
			while (is[l[j][pos[j]]])pos[j]++;
		memset(tot, 0, sizeof tot);
		for (int j = 1; j <= n; j++)
			tot[l[j][pos[j]]]++;
		int rres = 0;
		for (int j = 1; j <= m; j++)
			if (tot[j] > tot[rres])rres = j;
		res = min(res, tot[rres]);
		is[rres] = 1;
	}
	cout << res << endl;
	return 0;
}