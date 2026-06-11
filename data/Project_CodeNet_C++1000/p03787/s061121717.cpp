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

#define REP(i, n) for(int i = 0;i < (n);++i)
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
std::random_device rd;
std::mt19937 mt(rd());
constexpr int MOD = 1e9 + 7; constexpr int MAX = 200020;
const double pi = acos(-1); constexpr double EPS = 1e-8;
constexpr ll INF = 1e16;
typedef array<int, 3>arr3;
void die(string s) { cout << s << endl; exit(0); }
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };

vector<int>G[100010];

int siz[MAX];//錬結成分のサイズ
int par[MAX];//親
int Rank[MAX];//木の深さ

//n要素で初期化
void init(int n) {
	REP(i, n) {
		par[i] = i;
		Rank[i] = 0;
		siz[i] = 1;
	}
}

//木の根を求める
int find(int x) {
	if (par[x] == x) {
		return x;
	}
	else {
		return par[x] = find(par[x]);//経路圧縮(根に直接つなぎなおす)もしつつ
	}
}

//xとyの属する集合を併合
void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)return;
	//低いほうを高いほうにつなげる(効率化)
	if (Rank[x] < Rank[y]) {
		par[x] = y;
		siz[x] += siz[y];
		siz[y] = siz[x];
	}
	else {
		siz[y] += siz[x];
		siz[x] = siz[y];
		par[y] = x;
		if (Rank[x] == Rank[y])Rank[x]++;
	}
}

//xとyが同じ集合に属するか否か
bool same(int x, int y) {
	return find(x) == find(y);
}
int type[100010];

bool vis[100010];
int color[100010];
bool dfs(int n, int pre,int res) {
	color[n] = res;
	vis[n] = true;
	for (auto nxt : G[n]) {
		if (vis[nxt] && color[nxt] == color[n])return false;
		if (vis[nxt])continue;
		vis[nxt] = true;
		color[nxt] = (res + 1) % 2;
		if (!dfs(nxt, n, color[nxt]))return false;
	}
	return true;
}

void solve() {
	int N, M; cin >> N >> M;
	init(N);
	REP(i, M) {
		int u, v; cin >> u >> v;
		u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
		unite(u, v);
	}
	REP(i, N) {
		if (type[find(i)] != 0)continue;
		if (siz[find(i)] == 1)type[i] = 1;
		else {
			if (dfs(i, i, 0))type[find(i)] = 2;
			else type[find(i)] = 3;
		}
	}
	vector<int>c(4);
	REP(i, N) {
		if (find(i) == i) {
			c[type[i]]++;
		}
	}
	ll ans = 0;
	ans += c[1] * c[1];
	ans += 2 * c[1] * (N - c[1]);
	ans += 2 * c[2] * c[2];
	ans += 2 * c[2] * c[3];
	ans += c[3] * c[3];
	print(ans);
}




signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	//int q; cin >> q;
	//while (q--)
	solve();
}

