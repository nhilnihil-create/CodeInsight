//waz
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)((x).size()))

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long uint64;

#define gi(x) ((x) = F())
#define gii(x, y) (gi(x), gi(y))
#define giii(x, y, z) (gii(x, y), gi(z))

int F()
{
	char ch;
	int x, a;
	while (ch = getchar(), (ch < '0' || ch > '9') && ch != '-');
	if (ch == '-') ch = getchar(), a = -1;
	else a = 1;
	x = ch - '0';
	while (ch = getchar(), ch >= '0' && ch <= '9')
		x = (x << 1) + (x << 3) + ch - '0';
	return a * x;
}

PII x[510];

int a[510 * 510];

int n;

int main()
{
	gi(n);
	for (int i = 1; i <= n; ++i) gi(x[i].fi), x[i].se = i;
	int k = 1;
	sort(x + 1, x + n + 1);
	for (int i = 1; i <= n; ++i)
	{
		a[x[i].fi] = x[i].se;
		for (int j = 1; j < x[i].se; ++j)
		{
			while (a[k]) ++k;
			a[k] = x[i].se;
		}
		if (k > x[i].fi)
		{
			puts("No");
			return 0;
		}
	}
	k = 1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = x[i].se + 1; j <= n; ++j)
		{
			while (a[k]) ++k;
			if (k < x[i].fi)
			{
				puts("No");
				return 0;
			}
			a[k] = x[i].se;
		}
	}
	puts("Yes");
	for (int i = 1; i <= n * n; ++i)
		printf("%d ", a[i]);
}