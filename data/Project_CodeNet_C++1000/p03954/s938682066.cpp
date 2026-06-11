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

const int N = 2e5 + 10;

int n, a[N];

bool check(int mid)
{
	for (int i = 1; i <= n - 1; ++i)
	{
		if ((a[n + i - 1] >= mid) == (a[n + i] >= mid)) return a[n + i] >= mid;
		if ((a[n - i + 1] >= mid) == (a[n - i] >= mid)) return a[n - i] >= mid;
	}
	return a[1] >= mid;
}

int main()
{
	gi(n);
	for (int i = 1; i <= 2 * n - 1; ++i) gi(a[i]);
	int x = 1, v = 2 * n - 1;
	for (int i = 19; ~i; --i)
		if (x + (1 << i) <= v && check(x + (1 << i)))
			x += 1 << i;
	printf("%d\n", x);
}