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

int a[7], b[7];

int64 ans = 0, res = 0;

int main()
{
	for (int i = 0; i < 7; ++i) gi(a[i]), b[i] = a[i];
	ans += 4LL * (a[0] >> 1); a[0] &= 1;
	ans += 4LL * (a[3] >> 1); a[3] &= 1;
	ans += 4LL * (a[4] >> 1); a[4] &= 1;
	ans += 2LL * a[1]; a[1] = 0;
	if (a[0] && a[3] && a[4]) ans += 6;
	if (b[0] && b[3] && b[4]) --b[0], --b[3], --b[4], res += 6;
	res += 4LL * (b[0] >> 1);
	res += 4LL * (b[3] >> 1);
	res += 4LL * (b[4] >> 1);
	res += 2LL * b[1];
	printf("%lld\n", max(ans, res) >> 1);
}