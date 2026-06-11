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

const int MAXN = 100005;

int n, a[MAXN];

inline bool Solve()
{
	int cnt[2] = {0, 0}, d = 0;
	for (int i = 1; i <= n; i ++)
		cnt[a[i] & 1] ++;
	if (cnt[0] & 1)
		return true;
	if (cnt[1] ^ 1)
		return false;
	for (int i = 1; i <= n; i ++)
		if ((a[i] & 1) && (a[i] ^ 1))
		{
			a[i] --;
			for (int j = 1; j <= n; j ++)
				d = __gcd(d, a[j]);
			for (int j = 1; j <= n; j ++)
				a[j] /= d;
			return Solve() ^ 1;
		}
	return false;
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read();
	for (int i = 1; i <= n; i ++)
		a[i] = Read();
	if (n == 1)
		return puts("Second"), 0;
	return puts(Solve() ? "First" : "Second"), 0;
}
