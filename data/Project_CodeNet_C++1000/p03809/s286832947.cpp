#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include <string.h>
#include <set>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <string>
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

int A[MAXN];
vector <int> G[MAXN];
bool used[MAXN], flag = true;

void dfs(int v)
{
	used[v] = true;
	int cnt = 0, m = 0;
	LL s = 0;
	REP(i, SZ(G[v]))
	{
		int to = G[v][i];
		if (!used[to])
		{
			dfs(to);
			if (A[to])
				++cnt;
			s += A[to];
			m = max(m, A[to]);
		}
	}
	if (cnt)
	{
		if (2 * A[v] < s || A[v] > s || 2 * m + s > 4LL * A[v] || A[v] < s && cnt == 1)
			flag = false;
		A[v] = 2 * A[v] - s;
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	int n, r;
	cin >> n;
	REP(i, n)
		cin >> A[i];
	if (n == 2)
	{
		cout << (A[0] == A[1] ? "YES" : "NO");
		return 0;
	}
	REP(i, n - 1)
	{
		int a, b;
		cin >> a >> b;
		--a; --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	REP(i, n)
		if (SZ(G[i]) > 1)
			r = i;
	dfs(r);
	cout << (flag && A[r] == 0 ? "YES" : "NO");
	//cout << endl; system("pause");
	return 0;
}