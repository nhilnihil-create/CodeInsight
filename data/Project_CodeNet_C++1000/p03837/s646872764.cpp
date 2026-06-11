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
//gcdlcm, isPrime, eratos, Npow, divisor, modinv, bitSearch, bitList, dfs, bfs//
//dijkstra, UnionFind, COM, digitDP//
ll i, j, k, l; ll N, M, K, H, W, L, X, Y, Z;
ll MOD = 1000000007; ll INF = 1LL << 60; ll ans = 0; ll z = 0, o = 1;
vl flag, color, D; vector<vector<tuple<ll, ll, ll>>> path; ll goal = 0; vector<tuple<ll,ll,ll>> path2;
vll dis;
//***********//
void dijkstra(ll s) {
	priority_queue<pll> PQ;
	vl D(N), color(N);
	for (ll i = 0; i < N; i++) {
		D[i] = INF;
		color[i] = 0;
	}
	D[s] = 0;
	PQ.push(make_pair(0, s));
	color[0] = 1;
	ll q = -1;
	while (!PQ.empty()) {
		pll f = PQ.top();
		PQ.pop();
		ll u = f.second;
		color[u] = 2;
		if (D[u] < f.first * q) {
			continue;
		}
		for (ll j = 0; j < path[u].size(); j++) {
			ll v = get<0>(path[u][j]);
			if (color[v] == 2) {
				continue;
			}
			if (D[v] > D[u] + get<1>(path[u][j])) {
				D[v] = D[u] + get<1>(path[u][j]);
				color[v] = 1;
				PQ.push(make_pair(D[v] * q, v));
			}
		}
	}
	for (ll j = 0; j < N; j++) {
		dis[s].push_back(D[j]);
		//cout << (D[j] == INF ? -1 : D[j]) << endl;
	}
}
int main() {
	cin >> N >> M;
	path.resize(N);
	flag.resize(M*2);
	dis.resize(N);
	for (i = 0; i < M; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		path[a].push_back(make_tuple(b, c, i));
		path[b].push_back(make_tuple(a, c, i));
		path2.push_back(make_tuple(a, b, c));
		path2.push_back(make_tuple(a, b, c));
	}
	for (i = 0; i < N; i++) {
		dijkstra(i);
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			for (k = 0; k < M*2; k++) {
				ll s = get<0>(path2[k]);
				ll t = get<1>(path2[k]);
				ll c = get<2>(path2[k]);
				if (dis[i][s] + c + dis[t][j] == dis[i][j]) flag[k] = 1;
			}
		}
	}
	for (i = 0; i < M*2; i+=2) {
		if (flag[i] == 0 && flag[i+1] == 0) ans++;
	}
	cout << ans;
}
