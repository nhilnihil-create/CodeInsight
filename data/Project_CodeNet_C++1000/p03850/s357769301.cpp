#include <bits/stdc++.h>

template <class T>
inline void read(T &res)
{
	res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	if (bo) res = ~res + 1;
}

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

typedef long long ll;

const int N = 2e5 + 5, M = 4e6 + 5;

int n, a[N], add[N];
char s[M], op[N];
ll sum[N];

void work()
{
	int tot = 1, m; a[1] = 0;
	read(n); gets(s + 1);
	m = strlen(s + 1);
	for (int i = 1; i <= m; i++)
	{
		if (s[i] == ' ') continue;
		if (s[i] == '+' || s[i] == '-') op[tot++] = s[i], a[tot] = 0;
		else a[tot] = a[tot] * 10 + s[i] - '0';
	}
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	add[n] = 0;
	for (int i = n - 1; i >= 1; i--) add[i] = op[i] == '-' ? 0 : add[i + 1] + 1;
	ll cur = a[1], ans = -1e18;
	for (int i = 1; i < n; i++)
		if (op[i] == '-') ans = Max(ans, cur - (sum[i + 1 + add[i + 1]]
			- sum[i]) + sum[n] - sum[i + 1 + add[i + 1]]), cur -= a[i + 1];
		else cur += a[i + 1];
	printf("%lld\n", Max(cur, ans));
}


int main()
{
	int T = 1;
	while (T--) work();
	return 0;
}