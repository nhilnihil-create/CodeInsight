#pragma comment(linker, "/STACK:64777216")
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <stdio.h>
#include <cctype>
#include <algorithm>
#include <utility>
#include <cassert>
#include <complex>
#include <time.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b) - 1; i >= (a); i--)
#define ITER(it, a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a, value) memset(a, value, sizeof(a))

#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define MP make_pair
#define PB push_back

typedef long long Int;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;

const int MAX = 1000007;
const int CNT = 17;

int n;
VI G[MAX];
int R[MAX];

void dfs(int v, int p)
{
	FOR (i,0,SZ(G[v]))
	{
		int to = G[v][i];
		if (to == p) continue;
		dfs(to, v);
		R[v] ^= R[to];
	}
	++ R[v];
}

int main()
{
	//freopen("in.txt", "r", stdin);

	cin >> n;
	FOR (i,0,n-1)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		-- u;
		-- v;
		G[u].PB(v);
		G[v].PB(u);
	}

	dfs(0, -1);

	-- R[0];

	cout << (R[0] == 0 ? "Bob" : "Alice") << endl;





	return 0;
}
