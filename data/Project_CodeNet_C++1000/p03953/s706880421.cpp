#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
typedef long long ll;
template <class T>
inline void _read(T &x)
{
	x = 0;
	char t = getchar();
	while (!isdigit(t) && t != '-') t = getchar();
	if (t == '-')
	{
		_read(x);
		x *= -1;
		return ;
	}
	while (isdigit(t))
	{
		x = x * 10 + t - '0';
		t = getchar();
	}
}
template <class T>
inline void _read(T &a, T &b)  { _read(a), _read(b); } 
ll a[MAXN], id[MAXN], st[MAXN], n, m, k, vis[MAXN], ans[MAXN];
int main(int argc, char **argv)
{
	_read(n);
	for (int i = 1; i <= n; ++i) _read(a[i]), id[i] = i;
	for (int i = n; i ; --i) a[i] -= a[i - 1];
	_read(m, k);
	for (int i = 1, x; i <= m; ++i) _read(x), swap(id[x], id[x + 1]);
	for (int i = 1; i <= n; ++i)
	{
		if (!vis[i])
		{
			int  top = 0;
			for (int j = i; !vis[j]; j = id[j]) st[++top] = j, vis[j] = 1;
			for (int j = 1; j <= top; ++j) ans[st[j]] = a[st[(k + j - 1) % top + 1]];
		}
	}
	for (int i = 1; i <= n; ++i) ans[i] += ans[i - 1], printf("%lld\n", ans[i]);
	return 0;
}