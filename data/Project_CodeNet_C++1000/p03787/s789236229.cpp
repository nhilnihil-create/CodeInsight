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

int U[MAX];
int C[MAX];

int sz;

bool dfs(int x, int c)
{
	U[x] = true;

	C[x] = c;

	int res = false;
	sz++;

	FOR (i, 0, SZ(g[x]))
	{
		int to = g[x][i];
		if (U[to])
		{
			if (C[to] == C[x]) res = true;
		}
		else
		{
			if (dfs(to, c ^ 1)) res = true;
		}
	}

	return res;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//ios::sync_with_stdio(false); cin.tie(0);

	int n, m;
	scanf("%d%d", &n, &m);
	FOR (i, 0, m)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;

		g[x].PB(y);
		g[y].PB(x);
	}

	LL c1 = 0;
	LL c[2] = {0, 0};

	FOR (i, 0, n)
	{
		if (!U[i])
		{
			sz = 0;
			int r = dfs(i, 0);

			if (sz == 1) c1++;
			else c[r]++;
		}
	}

	LL res = 0;
	res += c1 * c1;


	res += (n-c1) * c1 * 2;

	res += c[1] * c[1];
	res += c[1] * c[0] * 2;
	res += c[0] * c[0] * 2;

	cout<<res<<endl;

}
