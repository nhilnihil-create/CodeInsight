#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cstring>
#include<string>
#include<cassert>
#include<cmath>
#include<climits>
#include<iomanip>
#include<bitset>
#include<unordered_map>

using namespace std;

#define rep(i,m,n) for(int (i)=(int)(m);(i)<(int)(n);(i)++)
#define rep2(i,m,n) for(int (i)=(int)(n)-1;(i)>=(int)(m);(i)--)
#define REP(i,n) rep(i,0,n)
#define FOR(i,c) for(decltype((c).begin())i=(c).begin();i!=(c).end();++i)
#define ll long long
#define ull unsigned long long
#define all(hoge) (hoge).begin(),(hoge).end()
#define en '\n'
typedef pair<ll, ll> P;
constexpr long long INF = 1LL << 60;
constexpr int INF_INT = 1 << 25;
constexpr long long MOD = 998244353;
typedef vector<ll> Array;
typedef vector<Array> Matrix;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;


template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

struct Edge {
	ll to, cap, rev;
	Edge(ll _to, ll _cap, ll _rev) {
		to = _to; cap = _cap; rev = _rev;
	}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

void add_edge(Graph& G, ll from, ll to, ll cap, bool revFlag, ll revCap) {
	G[from].push_back(Edge(to, cap, (ll)G[to].size()));
	if (revFlag)G[to].push_back(Edge(from, revCap, (ll)G[from].size() - 1));
}


//最大公約数
ll gcd(ll m, ll n) {
	if (n == 0)return m;
	return gcd(n, m % n);
}//gcd

 //最小公倍数
ll lcm(ll m, ll n) {
	return m / gcd(m, n) * n;
}


void solve() {

	ll n, k;
	cin >> n >> k;
	Array a(n);
	REP(i, n) cin >> a[i];

	ll d = a[0];//作れる最小の値
	REP(i, n) d = gcd(d, a[i]);
	bool flag = false;
	REP(i, n) {
		if (a[i] == k) {
			flag = true;
			break;
		}
		if (a[i] > k) {
			if ((a[i] - k) % d == 0) {
				flag = true; 
				break;
			}
		}
	}
	if (flag) cout << "POSSIBLE" << en;
	else cout << "IMPOSSIBLE" << en;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solve();
	//int t; cin >> t; REP(i, t) solve();

	return 0;
}
