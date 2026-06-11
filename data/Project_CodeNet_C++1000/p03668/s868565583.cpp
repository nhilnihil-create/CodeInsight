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

int go(int x, int p)
{
	int s = 0;
	FOR (i, 0, SZ(g[x]))
	{
		int to = g[x][i];
		if (to == p) continue;

		int v = go(to, x) + 1;

		s ^= v;
	}

	return s;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//ios::sync_with_stdio(false); cin.tie(0);

	int n;
	scanf("%d", &n);
	FOR (i, 0, n-1)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;

		g[x].PB(y);
		g[y].PB(x);
	}

	int v = go(0, -1);

	if (v == 0) cout<<"Bob"<<endl;
	else cout<<"Alice"<<endl;
}
