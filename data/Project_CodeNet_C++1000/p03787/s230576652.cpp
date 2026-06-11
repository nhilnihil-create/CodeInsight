#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include <string.h>
#include <set>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

typedef double LD;
typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define PB push_back
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i,0,t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())

const LL MOD = 1000000007;
const int INF = 1e9;
const LL LINF = 1LL * INF * INF;
const int MAXN = 100007;
const LD EPS = 1e-7;

vector <int> G[MAXN];
bool bip, used[MAXN];
int col[MAXN];

void dfs(int v)
{
	used[v] = true;
	REP(i, SZ(G[v]))
	{
		int to = G[v][i];
		if (!used[to])
		{
			col[to] = 3 - col[v];
			dfs(to);
		}
		if (col[to] != 3 - col[v])
			bip = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("In.txt", "r", stdin);
	int n, m;	
	cin >> n >> m;
	REP(i, m)
	{
		int u, v;
		cin >> u >> v;
		--u; --v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	LL b = 0, c = 0, c1 = 0;
	REP(i, n)
	{
		if (SZ(G[i]) == 0)
		{
			++c1;
			continue;
		}
		if (!used[i])
		{
			bip = true;
			col[i] = 1;
			dfs(i);
			if (bip)
				++b;
			++c;
		}
	}
	cout << c * c + b * b + c1 * (2 * n - c1);
	//cout << endl; system("pause");
	return 0;
}