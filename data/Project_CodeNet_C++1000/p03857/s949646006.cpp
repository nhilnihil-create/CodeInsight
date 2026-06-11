#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct _IO { _IO() { ios::sync_with_stdio(0); cin.tie(0); } }_io;
typedef long long ll; typedef long double db;

vector<int> road, railway;
map<pair<int, int>, int> ans;

int find(int x, vector<int>&fa)
{
	if (x != fa[x])
		fa[x] = find(fa[x], fa);
	return fa[x];
}
void merge(int x, int y, vector<int>&fa)
{
	x = find(x, fa);
	y = find(y, fa);
	if (x == y) return;
	else fa[x] = y;
}

int main()
{
	int n, k, l;
	cin >> n >> k >> l;

	road.assign(n + 5, -1);
	railway.assign(n + 5, -1);

	for (int i = 1; i <= n; ++i)
	{
		road[i] = i;
		railway[i] = i;
	}

	while (k--)
	{
		int a, b;
		cin >> a >> b;
		merge(a, b, road);
	}
	while (l--)
	{
		int a, b;
		cin >> a >> b;
		merge(a, b, railway);
	}

	for (int i = 1; i <= n; ++i)
		++ans[make_pair(find(i, road), find(i, railway))];

	for (int i = 1; i <= n; ++i)
	{
		cout << ans[make_pair(find(i, road), find(i, railway))];
		if (i != n) cout << " ";
	}
	cout << endl;
	return 0;
}