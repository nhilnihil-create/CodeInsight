#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma warning(disable : 4996)
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include<iterator>
#include<complex>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<time.h>
#include<random>
#include<array>


using namespace std;

#define REP(i, n) for(int i = 0;i < n;++i)
#define REPR(i, n) for(int i = n-1;i >= 0;--i)
#define FOR(i, m, n) for(int i = m;i < n;++i)
#define FORR(i, m, n) for(int i = m-1;i >= n;--i)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define VREVERSE(v) reverse(v.begin(), v.end())
#define ll long long
#define print(x) cout<<(x)<<'\n'
#define pe(x) cout<<(x)<<" "
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define lb(v,n) lower_bound(v.begin(), v.end(), (n))
#define ub(v,n) upper_bound(v.begin(), v.end(), (n))
#define int long long
//#define double long double
#define all(x) (x).begin(), (x).end()
#define print_space(v) REP(i,v.size())cout << v[i] << ((i == v.size() - 1) ? "\n" : " ")
template<typename T1, typename T2> inline void chmin(T1 & a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }
typedef pair<int, int>P;
typedef array<int, 3> arr3;
std::random_device rd;
std::mt19937 mt(rd());
constexpr int MOD = 1e9 + 7; constexpr int MAX = 2000020;
const double pi = acos(-1); constexpr double EPS = 1e-8;
constexpr ll INF = 1e18;


struct edge {
	int to, cost;
};

vector<int>G[100010];
map<int, int>cost[100010];
int parent[100010];
int depth[100010];
int A[100010];
int deg[100010];
void dfs(int n, int d) {
	depth[n] = d;
	//print(n);
	for (auto nxt : G[n]) {
		if (nxt == parent[n])continue;
		parent[nxt] = n;
		dfs(nxt, d + 1);
	}
}
void no() {
	print("NO"); exit(0);
}
void solve() {
	int N; cin >> N;
	REP(i, N) {
		cin >> A[i];
	}
	REP(i, N - 1) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}
	REP(i, N)if (deg[i] > 1)A[i] *= 2;
	dfs(0, 0);

	set<int>st;
	set<int>inner;
	REP(i, N)if (deg[i] > 1)inner.insert(i);
	FOR(i, 1, N)if (deg[i] == 1)st.insert(i);
	while (!st.empty()) {
		set<int>nxt;
		for (auto x : st) {
			//pe(x + 1); print(A[x]);
			if (A[x] < 0)no();
			int par = parent[x];
			cost[par][x] = cost[x][par] = A[x];
			A[par] -= A[x];
			deg[par]--;
			if (par != 0&&deg[par]==1)nxt.insert(par);
		}
		st.clear();
		for (auto x : nxt)st.insert(x);
	}
	//REP(i, N)pe(A[i]);
	//cout << endl;
	if (A[0] != 0)no();
	for(auto i:inner) {
		int sum = 0;
		int mx = 0;
		//print(i+1);
		for (auto nxt : G[i]) {
			sum += cost[i][nxt];
			mx = max(mx, cost[i][nxt]);
		}
		if (sum & 1)no();
		if (mx > sum / 2)no();
	}
	print("YES");
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	//int q; cin >> q;
	//while (q--)
	solve();
}

