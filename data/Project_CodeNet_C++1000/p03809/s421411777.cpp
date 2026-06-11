#include<bits/stdc++.h>
using namespace std;
int n, num[100007], f[100007];
vector<int>e[100007];
int read()
{
	int num = 0;
	char c = getchar();
	while (c < '0' || c>'9')c = getchar();
	while (c >= '0' && c <= '9')num = num * 10 + c - '0', c = getchar();
	return num;
}
int dfs(int w, int fa)
{
	if (e[w].size() == 1)
	{
		f[w] = num[w];
		return 0;
	}
	long long tot = 0, mx = 0;
	for (int i = e[w].size() - 1; i >= 0; i--)
		if (e[w][i] != fa)
		{
			dfs(e[w][i], w);
			tot += f[e[w][i]];
			mx = max(mx, 1LL * f[e[w][i]]);
		}
	f[w] = min(tot / 2, tot - mx);
	if (tot < num[w]) { cout << "NO" << endl; exit(0); }
	if (tot - f[w] > num[w]) { cout << "NO" << endl; exit(0); }
	f[w] = tot - (tot - num[w]) * 2;
	return 0;
}
int main()
{
	n = read();
	for (int i = 1; i <= n; i++)
		num[i] = read();
	for (int i = 1; i < n; i++)
	{
		int a = read(), b = read();
		e[a].push_back(b);
		e[b].push_back(a);
	}
	if (n == 2)
	{
		if (num[1] == num[2])cout << "YES" << endl;
		else cout << "NO" << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++)
		if (e[i].size() > 1)
		{
			dfs(i, 0);
			if (f[i])cout << "NO" << endl;
			else cout << "YES" << endl;
			break;
		}
	return 0;
}