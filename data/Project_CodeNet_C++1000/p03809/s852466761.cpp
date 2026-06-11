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

VI g[MAX];

LL A[MAX];

LL dfs(int x, int p)
{
	LL rest = A[x];

	FOR (i, 0, SZ(g[x]))
	{
		int to = g[x][i];
		if (to == p) continue;
		LL v = dfs(to, x);
		if (v < 0) return -1;
		if (SZ(g[x]) != 1)
		{
			if (v * 2 > A[x]) return -1;
		}
		rest -= v;
	}

	if (SZ(g[x]) != 1)
	{
		if (rest * 2 > A[x]) return -1;
	}

	return rest;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//ios::sync_with_stdio(false); cin.tie(0);

	int n;
	scanf("%d", &n);
	FOR (i, 0, n)
	{
		int x;
		scanf("%d", &x);
		A[i] = x;
	}

	FOR (i, 0, n-1)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		g[x].PB(y);
		g[y].PB(x);
	}

	FOR (i, 0, n)
	{
		if (SZ(g[i]) > 1) A[i] *= 2;
	}


	if (dfs(0, -1) != 0)
	{
		cout<<"NO"<<endl;
	}
	else
	{
		cout<<"YES"<<endl;
	}


}
