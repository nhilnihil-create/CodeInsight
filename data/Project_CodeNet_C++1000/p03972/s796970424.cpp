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
using namespace std; using ll = long long; using ld = long double;  using pll = pair<ll, ll>;
using vl = vector<ll>; using vll = vector<vl>; using vpll = vector<pll>;
const ld PI = 3.1415926535897932;
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define rep1(n) for(ll i=0;i<n;++i)
#define rep2(i,n) for(ll i=0;i<n;++i)
#define rep3(i,a,b) for(ll i=a;i<b;++i)
#define rep4(i,a,b,c) for(ll i=a;i<b;i+=c)
#define rep(...) overload4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)
#define mp make_pair
#define mt make_tuple
#define INT(...) int __VA_ARGS__;in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;in(__VA_ARGS__)
#define ULL(...) ull __VA_ARGS__;in(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;in(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;in(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;in(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__;in(__VA_ARGS__)
void in() {}
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
//rep, vin, all, iteLoop, bitSearch, bitList, nod//
//gcdlcm, isPrime, eratos, primeFactorize, Npow, combination, divisor, modinv,  digitDP//
//dfs, bfs, dijkstra, WarshallFloyd, BellmanFord, UnionFind, Kruskal ,RMQ, LCA//
ll i, j, k, l; ll N, M, K, H, W, L, X, Y, Z, R, Q; ll A, B;
ll MOD = 1000000007; ll INF = 1LL << 60; ll ans = 0; ll z = 0, o = 1;
vl flag, D; vll path; vl Ans;
//***********//
class UnionFind {
public:
	vl rank, par, siz;
	UnionFind() {}
	UnionFind(ll N) {
		rank.resize(N, 0);
		par.resize(N, 0);
		siz.resize(N, 1);
		init(N);
	}
	void init(ll N) {
		for (ll i = 0; i < N; i++) {
			par[i] = i;
			rank[i] = 0;
		}
	}
	ll find(ll x) {
		if (par[x] == x) {
			return x;
		}
		else {
			return par[x] = find(par[x]);
		}
	}
	void unite(ll x, ll y) {
		x = find(x);
		y = find(y);
		if (x != y) {
			if (rank[x] < rank[y]) {
				par[x] = y;
				siz[y] += siz[x];
			}
			else {
				par[y] = x;
				siz[x] += siz[y];
				if (rank[x] == rank[y]) rank[x]++;
			}
		}
	}
	bool issame(ll x, ll y) {
		return find(x) == find(y);
	}
	ll size(ll x) {
		return siz[find(x)];
	}
};
// 辺の定義
struct Edge { ll type, cost; };
bool comp_e(const Edge& e1, const Edge& e2) { return e1.cost < e2.cost; } // 辺を直接比較するための関数
/* Kruskal :クラスカル法で minimum spanning tree を求める構造体
	入力: 辺のvector, 頂点数V
	最小全域木の重みの総和: sum
	計算量: O(|E|log|V|)
*/
struct Kruskal {
	UnionFind UF;
	ll sum; vector<Edge> edges; ll V;
	Kruskal(const vector<Edge>& edges_, ll V_) : edges(edges_), V(V_) { init(); }
	void init() {
		sort(edges.begin(), edges.end(), comp_e); // 辺の重みでソート
		//UF = UnionFind(V); 
		sum = 0;
		for (auto e : edges) {
			if (true) { // 閉路にならなければ加える
				ll plus = 0;
				if (e.type == 0) {
					plus = B; A--;
				}else{
					plus = A; B--;
				}
				sum += e.cost * plus;
			}
		}
	}
};
int main() {
	cin >> W >> H;
	A = W + 1; B = H + 1;
	vl P(W), Q(H);
	vector<Edge> G;
	for (i = 0; i <=W-1; i++) {
		cin >> P[i];
		Edge e = { 0,P[i] };
		G.push_back(e);
	}
	for (i = 0; i <= H-1; i++) {
		cin >> Q[i];
		Edge e = { 1,Q[i] };
		G.push_back(e);
	}
	Kruskal Kr(G, H + W);
	cout << Kr.sum;
}