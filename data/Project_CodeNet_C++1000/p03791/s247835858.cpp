#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define fill(x, y) memset(x, y, sizeof x)
#define copy(x, y) memcpy(x, y, sizeof x)
using namespace std;

typedef long long LL;
typedef pair < int, int > pa;

inline int read()
{
	int sc = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') sc = sc * 10 + ch - '0', ch = getchar();
	return sc * f;
}

const int MAXN = 100005;
const int mod = 1e9 + 7;

int n, m, ans = 1, a[MAXN], b[MAXN];

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = read();
	for (int i = 1; i <= n; i ++) a[i] = read();
	b[m = 1] = 1;
	for (int i = 2; i <= n; i ++)
		if (a[i] ^ b[m] + 1)
			b[m + 1] = b[m] + 2, m ++;
		else ans = 1LL * ans * (m + 1) % mod;
	for (int i = 1; i <= m; i ++) ans = 1LL * ans * i % mod;
	return printf("%d\n", ans), 0;
}
