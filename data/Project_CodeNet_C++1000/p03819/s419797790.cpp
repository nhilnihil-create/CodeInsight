#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

const int MAXN = 300000 + 10000;

typedef pair<int, int> pii;

int lowbit(int x)
{
	return x & (-x);
}

struct BinaryIndexedTree
{
	int n, s[MAXN];
	void init(int _n)
	{
		n = _n;
		memset(s, 0, (n + 2) * sizeof(s[0]));
	}
	void add(int x, int v)
	{
		for(int i = x; i <= n; i += lowbit(i))
			s[i] += v;
	}
	int query(int x)
	{
		int ret = 0;
		for(int i = x; i >= 1; i -= lowbit(i))
			ret += s[i];
		return ret;
	}
}
bit;

int n, m;
pii seg[MAXN];

int cmp(const pii &a, const pii &b)
{
	return a.second - a.first < b.second - b.first;
}

int main()
{
	ios::sync_with_stdio(false);
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);

	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> seg[i].first >> seg[i].second;
	sort(seg + 1, seg + n + 1, cmp);
	bit.init(m);
	int p = 1;
	for(int i = 1; i <= m; i++)
	{
		while(p <= n && seg[p].second - seg[p].first < i)
			bit.add(seg[p].first, 1), bit.add(seg[p].second + 1, -1), p++;
		// cerr << i << endl;
		int ans = n - p + 1;
		for(int j = i; j <= m; j += i)
			ans += bit.query(j);
		cout << ans << endl;
	}


	return 0;
}
