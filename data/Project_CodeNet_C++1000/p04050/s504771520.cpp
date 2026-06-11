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

const int MAXN = 105;

int n, m, x, y, a[MAXN];

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), m = Read();
	if (m == 1)
	{
		a[1] = Read();
		if (a[1] == 1)
			puts("1\n1\n1");
		else
			printf("%d\n2\n1 %d\n", a[1], a[1] - 1);
		return 0;
	}
	for (int i = 1; i <= m; i ++)
		if ((a[i] = Read()) & 1)
			if (!x)
				x = i;
			else if (!y)
				y = i;
			else
				return puts("Impossible"), 0;
	if (x)
		swap(a[1], a[x]);
	if (y)
		swap(a[y], a[m]);
	for (int i = 1; i <= m; i ++)
		printf("%d%c", a[i], i == m ? '\n' : ' ');
	printf("%d\n", m - (a[m] == 1));
	printf("%d ", a[1] + 1);
	for (int i = 2; i < m; i ++)
		printf("%d ", a[i]);
	if (a[m] ^ 1)
		printf("%d", a[m] - 1);
	putchar(10);
	return 0;
}
