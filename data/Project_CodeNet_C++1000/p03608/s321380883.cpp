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
ll MOD = 1000000007; ll INF = 1LL << 60; ll ans = INF; ll z = 0, o = 1;
vl flag, color, D; vll path;
void warshall_floyd(int n) {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				path[i][j] = min(path[i][j], path[i][k] + path[k][j]);
			}
		}
	}
}
int main() {
	cin >> N >> M >> R;
	flag.resize(N);
	path.resize(N);
	D.resize(N);
	vl T(R);
	for (i = 0; i < R; i++) {
		cin >> T[i];
		T[i]--;
		flag[T[i]] = i + 1;
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			path[i].push_back(INF);
		}
	}
	for (i = 0; i < M; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		path[a][b] = c;
		path[b][a] = c;
	}
	warshall_floyd(N);
	sort(T.begin(), T.end());
	do {
		//debug(T);
		ll pre = 0;
		for (i = 0; i < R-1; i++) {
			pre += path[T[i]][T[i + 1]];
		}
		//debug(pre);
		ans = min(ans, pre);
	} while (next_permutation(T.begin(), T.end()));
	cout << ans;
}