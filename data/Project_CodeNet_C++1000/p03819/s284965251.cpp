#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int maxm = 100100;
const int maxn = 300100;
int m;
namespace BIT
{
	int v[maxm];
	int lowbit(int x)
	{
		return x & -x;
	}
	void add(int pos, int a)
	{
		for(int i = pos; i <= m; i += lowbit(i))
			v[i] += a;
	}
	int sum(int pos)
	{
		int ans = 0;
		for(int i = pos; i; i -= lowbit(i))
			ans += v[i];
		return ans;
	}
}
struct segment
{
	int l, r;
	bool operator<(const segment &a) const
	{
		return r - l + 1 < a.r - a.l + 1;
	}
}s[maxn];
int n;
int main()
{
	//freopen("Snuke10.in", "r", stdin);
	//freopen("Snuke10.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	using namespace BIT;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		cin >> s[i].l >> s[i].r;
	sort(s + 1, s + n + 1);
	int j = 1;
	for(int i = 1; i <= m; i ++)
	{
		for(; j <= n && s[j].r - s[j].l + 1 < i; j ++)
		{
			add(s[j].l, 1);
			add(s[j].r + 1, -1);
		}
		int ans = 0;
		for(int j = 0; j <= m; j += i)
			ans += sum(j);
		cout << ans + n - j + 1 << endl;
	}
	return 0;
}