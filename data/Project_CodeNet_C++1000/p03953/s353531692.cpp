#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i, a, b) for (i = a; i <= b; i++)
#define Rof(i, a, b) for (i = a; i >= b; i--)

inline int read()
{
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

template <class T>
inline void Swap(T &a, T &b) {a ^= b; b ^= a; a ^= b;}

typedef long long ll;

const int N = 1e5 + 5;

int n, x[N], m, a[N], tr[N], st[N], tmp[N];
ll k, ans;

int main()
{
	int i;
	n = read();
	For (i, 1, n) x[i] = read();
	Rof (i, n, 2) x[i] -= x[i - 1];
	m = read(); std::cin >> k;
	For (i, 1, m) a[i] = read();
	For (i, 1, n) tr[i] = st[i] = i;
	For (i, 1, m) Swap(tr[a[i]], tr[a[i] + 1]);
	while (k)
	{
		if (k & 1) For (i, 1, n) st[i] = tr[st[i]];
		For (i, 1, n) tmp[i] = tr[tr[i]];
		For (i, 1, n) tr[i] = tmp[i];
		k >>= 1;
	}
	For (i, 1, n)
	{
		ans += x[st[i]];
		printf("%lld.000000000\n", ans);
	}
	return 0;
}