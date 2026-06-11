#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef long long LL;

#define re register
#define gc getchar
#define digit(x) (x >= '0' && x <= '9')

int read()
{
	int x = 0, f = 1; char c = getchar();
	while (!digit(c)) {if (c == '-') f = -1; c = gc();}
	while (digit(c)) x = (x << 3) + (x << 1) + c - '0', c = gc();
	return x * f;
}

const int N = 2005;
const LL inf = 0x3f3f3f3f3f3f3f3f;

int n, x;
int a[N];
int sk[N << 1], pos[N << 1], tp, tl;

inline int P(int x, int y)
{
	if (x < y) return y - x;
	return y - x + n;
}

int main()
{
	n = read(); x = read();
	
	for (re int i = 1; i <= n; i++)
		a[i] = read();
	
	LL ans = inf;
	for (re int i = 0; i < n; i++)
	{
		tl = tp = 0;
		LL tmp = 0;
		for (re int j = i; j >= 1; j--)
		{
			while (tl < tp && sk[tp - 1] >= a[n - j + 1]) tp--;
			sk[tp] = a[n - j + 1], pos[tp++] = n - j + 1;
		}
		for (re int j = 1; j <= n; j++)
		{
			while (tl < tp && P(pos[tl], j) > i) tl++;
			while (tl < tp && sk[tp - 1] >= a[j]) tp--;
			sk[tp] = a[j], pos[tp++] = j;
			tmp += sk[tl];
		}
		ans = min(ans, tmp + 1ll * i * x);
	}
	printf("%lld\n", ans);
	return 0;
}