#include<bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;
const ll INF = 1000000000000000000;
const ll mod = 1000000007;
const ld pi = 3.141592653589793238;
//printf("%.10f\n", n);

ll gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	if (a % b == 0)return b;
	return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}
ll modpow(ll x, ll y) {
	ll res = 1;
	while (y) {
		if (y % 2) { res *= x; res %= mod; }
		x = x * x % mod; y /= 2;
	}
	return res;
}

//頂点fromから頂点toへのコストcostの辺
struct edge { ll from, to, cost; };
edge es[345678]; //辺
ll d[345678]; //最短距離
//Vは頂点数、Eは辺数
//s番目の頂点から各頂点への最短距離を求める
void Bellman_Ford(ll V, ll E, ll s) {
	for (int i = 0; i <= V; i++) d[i] = INF;
	d[s] = 0; ll sum = 0;
	for (int z = 0; z < V; z++) {
		for (int i = 0; i < E; i++) {
			edge e = es[i];
			if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
				d[e.to] = d[e.from] + e.cost;
			}
		}
	}
}
//trueなら負の経路が存在する
bool find_negative_loop(ll V, ll E) { //Vは頂点数、Eは辺数
	memset(d, 0, sizeof(d)); ll sum = 0;
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < E; j++) {
			edge e = es[j];
			if (d[e.to] > d[e.from] + e.cost) {
				d[e.to] = d[e.from] + e.cost;
				//n回目にも更新があるなら負の経路が存在
				if (i == V - 1 && d[V] != sum)return true;
			}
		}
		if (i == V - 2) { sum = d[V]; }
	}
	return false;
}
ll test[12345678];
signed main() {
	ll n, m, a, b, c; cin >> n >> m;
	for (int h = 0; h < m; h++) {
		cin >> a >> b >> c;
		es[h] = { a, b, 0 - c };
	}
	if (find_negative_loop(n, m)) { cout << "inf" << endl; return 0; }
	Bellman_Ford(n, m, 1);
	cout << 0 - d[n] << endl;
	return 0;
}