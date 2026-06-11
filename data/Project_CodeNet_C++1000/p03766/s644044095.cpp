#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define mset(x, y) memset(x, y, sizeof x)
#define mcpy(x, y) memcpy(x, y, sizeof x)
using namespace std;

typedef long long LL;
typedef pair <int, int> pii;

inline int Read()
{
	int x = 0, f = 1, c = getchar();
	for (; !isdigit(c); c = getchar())
		if (c == '-')
			f = -1;
	for (;  isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x * f;
}

const int MAXN = 1000005;
const int mod = 1e9 + 7;

int n, sum, f[MAXN];

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	f[1] = n = Read(), f[2] = 1LL * n * n % mod, sum = (f[1] + f[2]) % mod;
	for (int i = 3; i <= n; i ++)
		f[i] = (1LL * (n - 1) * (n - 1) + sum - f[i - 2] + n - i + 2) % mod, sum = (sum + f[i]) % mod;
	return printf("%d\n", (f[n] + mod) % mod), 0;
}
