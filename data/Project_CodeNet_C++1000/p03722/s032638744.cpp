#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string.h>
#include <cstdio>
#include <tuple>
using namespace std; using ll = long long; using pll = pair<ll, ll>;
using vl = vector<ll>; using vll = vector<vl>; using vpll = vector<pll>;
//**デバッグ準備**//
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
void debug_out() { cerr << endl; }
template<typename Head, typename... Tail>
void debug_out(Head h, Tail... t) {
	cerr << " " << h;
	if (sizeof...(t) > 0) cerr << " :";
	debug_out(t...);
}
template <typename T>
ostream& operator<<(ostream& os, vector<T> vec) {
	for (size_t i = 0; i < vec.size(); i++)os << vec[i] << (i + 1 == vec.size() ? "" : " ");
	return os;
}
ll ctoi(char c) {
	switch (c) {
	case '0': return 0; case '1': return 1; case '2': return 2;
	case '3': return 3; case '4': return 4; case '5': return 5;
	case '6': return 6; case '7': return 7; case '8': return 8;
	case '9': return 9;  default: return 0;
	}
}
bool pairCompare(const pll firstElof, pll secondElof)
{
	return firstElof.first > secondElof.first;
}
//**Snippetリスト**//
//rep, vin, all, iteLoop//
//bitSearch, bitList, gcdlcm, isPrime, primeFactorize, Npow, divisor, modinv, dfs, bfs, eratos//
//dijkstra, WarshallFloyd, BellmanFord, UnionFind, COM, digitDP ,RMQ//
ll i, j, k, l; ll N, M, K, H, W, L, X, Y, Z, R;
ll MOD = 1000000007; ll INF = 1LL << 60; ll ans = 0; ll z = 0, o = 1;
vl flag, color, D; vll path;
//add_edge:辺の追加, build:from→toへの経路探索+負の閉路検出
template<typename T>
struct BellmanFord {
	struct Edge {
		ll from, to; ll cost;
		Edge() {}
		Edge(ll from, ll to, ll cost) :from(from), to(to), cost(cost) {}
	};
	ll n; vll G; vl used, reach;
	BellmanFord(ll n) :n(n), G(n), used(n, 0), reach(n, 0) {}

	vector<Edge> es;
	void add_edge(ll from, ll to, ll cost) {
		es.push_back(Edge(from, to, cost));
		G[from].push_back(to);
	}
	void dfs(ll v) {
		if (used[v]) return;
		used[v] = 1;
		for (ll u : G[v]) dfs(u);
	}
	ll build(ll from, ll to, ll& neg_loop) {
		for (ll i = 0; i < n; i++) {
			fill(used.begin(), used.end(), 0);
			dfs(i);
			reach[i] = used[to];
		}
		vector<ll> ds(n, 1e18);
		ds[from] = 0;
		for (ll i = 0; i < n; i++) {
			bool update = 0;
			for (auto e : es) {
				if (!reach[e.from] || !reach[e.to] || ds[e.from] == 1e18) continue;
				if (ds[e.to] > ds[e.from] + e.cost) {
					ds[e.to] = ds[e.from] + e.cost;
					update = 1;
				}
			}
			if (!update)break;
			if (i == n - 1) {
				neg_loop = 1;
				return INF;
			}
		}
		neg_loop = 0;
		return ds[to];
	}
};
int main() {
	cin >> N >> M;
	BellmanFord<ll> G(N);
	for (i = 0; i < M; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--; b--; c *= (-1);
		G.add_edge(a, b, c);
	}
	ll NL;
	ll res = G.build(0, N - 1, NL);
	if (NL) cout << "inf";
	else cout << -res;
}