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

LL f[MAXN][3];
char opt[2];
int n;

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), f[0][0] = Read(), f[0][1] = f[0][2] = -1LL << 60;
	for (int i = 1; i < n; i ++)
	{
		scanf("%s", opt);
		int x = Read();
		if (opt[0] == '+')
		{
			f[i][2] = f[i - 1][2] + x;
			f[i][1] = max(f[i][2], f[i - 1][1] - x);
			f[i][0] = max(f[i][1], f[i - 1][0] + x);
		}
		else
		{
			f[i][2] = f[i - 1][1] + x;
			f[i][1] = max(f[i][2], max(f[i - 1][0], f[i - 1][2]) - x);
			f[i][0] = max(f[i][1], f[i - 1][1] + x);
		}
	}
	return printf("%lld\n", max(max(f[n - 1][0], f[n - 1][1]), f[n - 1][2])), 0;
}
