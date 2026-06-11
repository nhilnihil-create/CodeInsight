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

const int N = 100010;

void mul(int *a, int *b, int n)
{
	static int t[N], h[N];
	for (int i = 1; i <= n; ++i) t[i] = a[i], h[i] = b[i];
	for (int i = 1; i <= n; ++i) a[i] = t[h[i]];
}

void fpow(int *a, int n, long long k)
{
	static int t[N];
	for (int i = 1; i <= n; ++i) t[i] = i;
	for (; k; k >>= 1)
	{
		if (k & 1) mul(t, a, n);
		mul(a, a, n);
	}
	for (int i = 1; i <= n; ++i) a[i] = t[i];
}

int n;

long long x[N];

int m, a[N];

long long k;

int main()
{	
	gi(n);
	for (int i = 1; i <= n; ++i) gi(x[i]), a[i] = i;
	for (int i = n; i; --i) x[i] -= x[i - 1];
	gi(m);
	scanf("%lld", &k);
	for (int i = 1; i <= m; ++i)
	{
		int p;
		gi(p);
		swap(a[p], a[p + 1]);
	}
	fpow(a, n, k);
	for (int i = 1; i <= n; ++i)
	{
		//cerr << a[i] << " : " << x[a[i]] << endl;
		x[a[i]] += x[a[i - 1]];
		printf("%lld\n", x[a[i]]);
	}
	return 0;
}