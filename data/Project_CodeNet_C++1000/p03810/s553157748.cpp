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

const int N = 1e5 + 10;

int n, a[N];

void dfs(int x)
{
	long long s = 0;
	for (int i = 1; i <= n; ++i) 
		s += a[i] - 1;
	if (s & 1)
	{
		puts(x ? "Second" : "First");
		return;
	} 
	int cnt = 0;
	for (int i = 1; i <= n; ++i)
		if (a[i] & 1) ++cnt;
	for (int i = 1; i <= n; ++i)
		if (a[i] == 1) cnt = 233;
	if (cnt != 1)
	{
		puts(x ? "First" : "Second");
		return;
	}
	for (int i = 1; i <= n; ++i) 
		if (a[i] & 1) --a[i];
	int v = 0;
	for (int i = 1; i <= n; ++i) v = __gcd(v, a[i]);
	for (int i = 1; i <= n; ++i) a[i] /= v;
	dfs(x ^ 1);
}

int main()
{
	gi(n);
	for (int i = 1; i <= n; ++i) gi(a[i]);
	dfs(0);
}