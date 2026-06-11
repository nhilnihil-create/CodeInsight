#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <queue>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <stdio.h>
#include <complex>
#include <cstdint>
#include <tuple>

#define M_PI       3.14159265358979323846

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }
inline int readInt() { int x; scanf("%d", &x); return x; }

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;

//container util

//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SQ(a) (a*a)
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,s,n) for(int i=s;i<(int)n;++i)
#define REP(i,n) FOR(i,0,n)
#define MOD 1000000007

using graph = VVI;

void dfs(graph &g, int node, vector<bool> &visit, deque<int> &q, int mode) {
	for (int i = 0; i < g[node].size(); i++) {
		if (visit[g[node][i]])continue;

		visit[g[node][i]] = true;
		if (mode == 0)q.push_front(g[node][i]);
		else q.push_back(g[node][i]);
		dfs(g, g[node][i], visit, q, mode);
		return;
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto g = graph(n);
	vector<bool> visit(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--, v--;
		g[u].PB(v);
		g[v].PB(u);
	}
	int x = 0, y = g[0][0];
	visit[x] = true;
	visit[y] = true;
	deque<int> q;
	q.push_back(x);
	q.push_back(y);
	dfs(g, x, visit, q, 0);
	dfs(g, y, visit, q, 1);
	printf("%d\n", q.size());
	while (!q.empty()) {
		auto tmp = q.front();
		q.pop_front();
		printf("%d ", tmp+1);
	}
	printf("\n");
	return 0;
}