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

int n, l, t;

int x[N], w[N];

int main()
{
	giii(n, l, t);
	long long v = 0;
	for (int i = 1; i <= n; ++i) 
	{
		gii(x[i], w[i]);
		if (w[i] == 1)
		{
			x[i] += t;
			v += x[i] / l;
			x[i] %= l;
		}
		else
		{
			x[i] -= t;
			if (x[i] < 0)
			{
				v += (x[i] - (l - 1)) / l;
			}
			x[i] %= l;
			if (x[i] < 0) x[i] += l; 
		}
	}
	sort(x + 1, x + n + 1);
	v %= n;
	if (v < 0) v += n;
	for (int i = 1; i <= n; ++i)
	{
		int j = i + v;
		if (j > n) j -= n;
		printf("%d\n", x[j]);
	}
	return 0;
} 