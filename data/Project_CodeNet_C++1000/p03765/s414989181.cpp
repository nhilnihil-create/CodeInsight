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
#include <numeric>
using namespace std; using ll = long long; using ld = long double;  using pll = pair<ll, ll>;
using vl = vector<ll>; using vll = vector<vl>; using vpll = vector<pll>;
using vs = vector<string>; using tll = tuple<ll, ll, ll>; using vtll = vector<tll>;
const ld PI = 3.1415926535897932;
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define co(i) cout << i << endl;
#define co2(i,j) cout << i << " " << j << endl;
#define co3(i) cout << i << " ";
#define po(i) cout << i.first << " " << i.second << endl;
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
//rep, vin, all, iteLoop, bitSearch, bitList, nod, digitDP, treeDP//
//gcdlcm, isPrime, eratos, primeFactorize, Npow, combination, divisor, modinv, doubling//
//dfs, bfs, dijkstra, WarshallFloyd, BellmanFord, UnionFind, Kruskal, RMQ, LCA//
ll i, j, k, l; ll N, M, K, H, W, L, X, Y, Z, R, Q;
ll MOD = 1000000007, INF = 1LL << 60, ans = 0, z = 0, o = 1;
vpll flag, D; vll path;
//***********//
int main() {
	string S, T;
	cin >> S >> T;
	cin >> Q;
	N = S.length();
	M = T.length();
	vl Sa(N + 1), Sb(N + 1), Ta(M + 1), Tb(M + 1);
	for (i = 0; i < N; i++) {
		Sa[i + 1] = Sa[i];
		Sb[i + 1] = Sb[i];
		if (S[i] == 'A') Sa[i + 1]++;
		else Sb[i + 1]++;
	}
	for (i = 0; i < M; i++) {
		Ta[i + 1] = Ta[i];
		Tb[i + 1] = Tb[i];
		if (T[i] == 'A') Ta[i + 1]++;
		else Tb[i + 1]++;
	}
	for (k = 0; k < Q; k++) {
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		ll Ds = (Sa[b] - Sa[a - 1]) - (Sb[b] - Sb[a - 1]);
		ll Dt = (Ta[d] - Ta[c - 1]) - (Tb[d] - Tb[c - 1]);
		if ((Ds - Dt) % 3 == 0) cout <<"YES"<<endl;
		else cout <<"NO"<<endl;
	}
}