#pragma GCC optimize(3)
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<queue>
#include<stack>
#include<bitset>
#include<deque>
using namespace std;
#define ll long long
// #define inf 0x3f3f3f3f
#define ri register int
#define il inline
#define fi first
#define se second
#define mp make_pair
#define pi pair<int,int>
#define mem0(x) memset((x),0,sizeof (x))
#define mem1(x) memset((x),0x3f,sizeof (x))
il char gc()
{
	static const int BS = 1 << 22;
	static unsigned char buf[BS], *st, *ed;
	if (st == ed) ed = buf + fread(st = buf, 1, BS, stdin);
	return st == ed ? EOF : *st++;
}
#define gc getchar
template<class T>void in(T &x)
{
	x = 0;
	bool f = 0;
	char c = gc();
	while (c < '0' || c > '9')
	{
		if (c == '-') f = 1;
		c = gc();
	}
	while ('0' <= c && c <= '9')
	{
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = gc();
	}
	if (f) x = -x;
}
#undef gc
#define pb push_back
ll n;
int s[500], hd = 250, tl = 249;
int dfs(ll x)
{
	if (x == 0) return 0;
	if (x == 1)
	{
		s[++tl] = 1;
		return 1;
	}
	if (x & 1)
	{
		int t = dfs(x >> 1);
		s[++tl] = t + 1;
		return t + 1;
	}
	else
	{
		int t = dfs(x - 1);
		s[--hd] = t + 1;
		return t + 1;
	}
}
signed main()
{
#ifndef ONLINE_JUDGE
	//freopen("in.in", "r", stdin);
#endif
	in(n);
	dfs(n);
	printf("%d\n", 100 + tl - hd + 1);
	for (ri i = 1; i <= 100; ++i) printf("%d ", i);
	for (ri i = hd; i <= tl; ++i) printf("%d ", s[i]);
	return 0;
}
