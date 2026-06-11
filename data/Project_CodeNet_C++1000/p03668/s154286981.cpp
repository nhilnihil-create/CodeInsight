#include<bits/stdc++.h>
using namespace std;
int n, sg[200007];
vector<int>e[200007];
int read()
{
	int num = 0;
	char c = getchar();
	while (c < '0' || c>'9')c = getchar();
	while (c >= '0' && c <= '9')num = num * 10 + c - '0', c = getchar();
	return num;
}
int dfs(int w, int f)
{
	for (int i = e[w].size() - 1; i >= 0; i--)
		if (e[w][i] != f)
			sg[w] ^= dfs(e[w][i], w) + 1;
	return sg[w];
}
int main()
{
	n = read();
	for (int i = 1; i < n; i++)
	{
		int a = read(), b = read();
		e[a].push_back(b);
		e[b].push_back(a);
	}
	cout << (dfs(1, 0) ? "Alice" : "Bob") << endl;
	return 0;
}