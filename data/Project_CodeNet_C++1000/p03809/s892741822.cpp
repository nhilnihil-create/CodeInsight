#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <iterator>
#include <functional>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <list>
#include <sstream>
#include <cstring>
#include <stdio.h>
#include <complex>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<LD, LD> PDD;
typedef pair<LL, int> PLL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<char> VCH;
typedef vector<LD> VLD;
typedef vector<string> VS;
typedef vector<VS> VSS;
typedef vector<VI> VVI;
typedef vector<VLL> VVLL;
typedef vector<VCH> VVCH;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<PDD> VPDD;
#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define next fake_next
#define prev fake_prev
#define left fake_left
#define right fake_right

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i,0,t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))

const LD PI = acos(-1.0);
const LD EPS = 1e-4;
const LL INF = 1e7 - 1;
const LL mod = 1000000007;
const LL LINF = 1e18 + 10;
const int MAXN = 100001;
const int MAXK = 101;

int n;
VLL a;
VLL SS;
VLL max_in;
VVI g;
int root;

void dfs(int v, int p = -1)
{
	if (SZ(g[v]) == 1)
	{
		max_in[p] = max(max_in[p], a[v]);
		a[p] -= a[v];
		if (a[p] < 0)
		{
			cout << "NO";
			exit(0);
		}

		a[v] = 0;
		return;
	}

	for (auto i : g[v])
		if (i != p)
			dfs(i, v);

	if (a[v] && p == -1)
	{
		cout << "NO";
		exit(0);
	}

	if (a[v])
	{
		max_in[p] = max(max_in[p], a[v]);
		max_in[v] = max(max_in[v], a[v]);
		a[p] -= a[v];
		a[v] = 0;
		if (a[p] < 0)
		{
			cout << "NO";
			exit(0);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	cin >> n;
	g.resize(n);
	a.resize(n);
	max_in.assign(n, 0);
	FOR(i, 0, n)
		cin >> a[i];

	SS = a;
	FOR(i, 0, n - 1)
	{
		int u, v;
		cin >> u >> v;
		--u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	if (n == 2)
	{
		if (a[0] == a[1])
			cout << "YES";
		else
			cout << "NO";
		return 0;
	}

	FOR(i, 0, n)
		if (SZ(g[i]) > 1)
		{
			root = i;
			break;
		}

	FOR(i, 0, n)
		if (SZ(g[i]) > 1)
			a[i] *= 2LL;

	dfs(root);
	FOR(i, 0, n)
		if (a[i] || (max_in[i] > SS[i]))
		{
			cout << "NO";
			return 0;
		}

	cout << "YES";
	cin >> n;
	return 0;
}