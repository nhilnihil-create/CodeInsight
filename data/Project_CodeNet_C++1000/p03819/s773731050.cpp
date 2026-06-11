#include<bits/stdc++.h>
using namespace std;
int n, m, t[100007];
pair<int, int>p[300007];
int read()
{
	int num = 0;
	char c = getchar();
	while (c < '0' || c>'9')c = getchar();
	while (c >= '0' && c <= '9')num = num * 10 + c - '0', c = getchar();
	return num;
}
int cmp(pair<int, int>a, pair<int, int>b)
{
	return a.second - a.first < b.second - b.first;
}
int add(int x, int v)
{
	while (x <= m)t[x] += v, x += x & -x;
	return 0;
}
int ask(int x)
{
	int res = 0;
	while (x)res += t[x], x -= x & -x;
	return res;
}
int main()
{
	n = read();
	m = read();
	for (int i = 1; i <= n; i++)
	{
		p[i].first = read();
		p[i].second = read();
	}
	sort(p + 1, p + n + 1, cmp);
	int pos = 1;
	for (int i = 1; i <= m; i++)
	{
		while (pos <= n && p[pos].second - p[pos].first + 1 < i)
		{
			add(p[pos].first, 1);
			add(p[pos].second + 1, -1);
			pos++;
		}
		int res = n - (pos - 1);
		for (int j = 1; i * j <= m; j++)
			res += ask(i * j);
		printf("%d\n", res);
	}
	return 0;
}