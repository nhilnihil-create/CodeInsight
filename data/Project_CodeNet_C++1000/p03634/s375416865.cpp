#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using V = vector<int>;
using VV = vector<V>;
using VVV = vector<VV>;
using VL = vector<ll>;
using VVL = vector<VL>;
using VVVL = vector<VVL>;
template<class T> using VE = vector<T>;
template<class T> using P = pair<T, T>;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define REP(i,k,n) for(int i=(k);i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define output(x,y) cout << fixed << setprecision(y) << x << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;
ll upper = MOD + MOD;
ll under = -upper;
ll UPPER = MOD * MOD;
ll UNDER = -UPPER;
const long double pi = 3.141592653589793;
const int N = 101010;
VL dist(N, UPPER);
void dfs(int x, VE<VE<P<int>>>& G, ll Dist, VE<bool>&visited) { // 実は木上の最短経路はdfsで行ける
	visited[x] = true;
	dist[x] = Dist;
	for (auto c : G[x]) {
		if (!visited[c.first]) {
			dfs(c.first, G, Dist + c.second, visited);
		}
	}
	visited[x] = false;
}
int main() {
	int n;
	cin >> n;
	VE<VE<P<int>>> G(n);
	rep(i, n - 1) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		a--, b--;
		G[a].push_back(make_pair(b, c));
		G[b].push_back(make_pair(a, c));
	}
	int q, k;
	cin >> q >> k;
	k--;
	dist[k] = 0;
	VE<bool> visited(N, false);
	dfs(k, G, 0, visited);
	while (q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--, y--;
		printf("%lld\n", dist[x] + dist[y]);
	}
	return 0;
}