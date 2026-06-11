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

long long n;

deque<int> l, r;

int tot;

void solve(long long n)
{
	if (n == 1) return;
	solve(n >> 1);
	l.push_front(++tot);
	r.push_front(tot);
	if (n & 1)
	{
		l.push_front(++tot);
		r.push_back(tot);
	}
}

int main()
{
	scanf("%lld", &n);
	solve(n + 1);
	printf("%d\n", l.size() + r.size());
	for (auto x : l) printf("%d ", x);
	for (auto x : r) printf("%d ", x);
	return 0;
}