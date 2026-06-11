#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); i--)
#define ITER(it, a) for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a, value) memset(a, value, sizeof(a))

#define SZ(a) (int) a.size()
#define ALL(a) a.begin(),a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const LL INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL)INF;

const int MAX = 100100;

int X[MAX];
int A[MAX];

LL RES[MAX];

VI go(VI& p1, VI& p2)
{
	VI res(SZ(p1));
	FOR (i, 0, SZ(p1))
	{
		res[i] = p2[p1[i]];
	}

	return res;
}

VI go(VI& p, LL k)
{
	VI res;
	FOR (i, 0, SZ(p))
	{
		res.PB(i);
	}

	while(k)
	{
		if (k & 1) res = go(res, p);
		p = go(p, p);
		k /= 2;
	}

	return res;
}

int main()
{
	//freopen("in.txt","r", stdin);
	//ios::sync_with_stdio(false); cin.tie(0);

	int n;
	scanf("%d", &n);
	FOR (i, 0, n)
	{
		scanf("%d", &X[i]);
	}

	int m;
	LL k;
	scanf("%d%lld", &m, &k);
	FOR (i, 0, m)
	{
		scanf("%d", &A[i]);
	}

	VI p(n - 1);
	FOR (i, 0, n-1)
	{
		p[i] = i;
	}

	FOR (i, 0, m)
	{
		swap(p[A[i] - 1], p[A[i] - 2]);
	}

	p = go(p, k);

	RES[0] = X[0];
	FOR (i, 0, SZ(p))
	{
		RES[i+1] = RES[i] + X[p[i]+1] - X[p[i]];
	}

	FOR (i, 0, n)
	{
		printf("%lld\n", RES[i]);
	}



}
