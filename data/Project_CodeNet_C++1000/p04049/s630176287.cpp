
#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
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
#include <cstdio>
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
#define SQ(a) ((a)*(a))
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,s,n) for(int i=s;i<(int)n;++i)
#define REP(i,n) FOR(i,0,n)
#define MOD 1000000007

int dfs(VVI& g, int v, int p, int depth, int k) {
	int ret = 0;
	if (depth > k) {
		ret++;
	}
	for (auto to : g[v]) {
		if (to != p)ret += dfs(g, to, v, depth + 1, k);
	}
	return ret;
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	VVI g(n);
	vector<PII> edges(n - 1);
	REP(i, n - 1) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--, v--;
		g[u].PB(v);
		g[v].PB(u);
		edges[i] = MP(min(u, v), max(u, v));
	}
	int ans = 1e9;
	if (k % 2) {
		REP(i, n - 1) {
			ans = min(ans, dfs(g, edges[i].first, edges[i].second, 0, k / 2) + dfs(g, edges[i].second, edges[i].first, 0, k / 2));
		}
	}
	else {
		REP(i, n) {
			ans = min(ans, dfs(g, i, i, 0, k / 2));
		}
	}
	cout << ans << endl;
	return 0;
}