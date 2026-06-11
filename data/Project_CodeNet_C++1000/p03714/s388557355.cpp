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
//rep, vin, all, iteLoop, bitSearch, bitList, nod//
//gcdlcm, isPrime, eratos, primeFactorize, Npow, combination, divisor, modinv, doubling, digitDP//
//dfs, bfs, dijkstra, WarshallFloyd, BellmanFord, UnionFind, Kruskal, RMQ, LCA//
ll i, j, k, l; ll N, M, K, H, W, L, X, Y, Z, R, Q;
ll MOD = 1000000007, INF = 1LL << 60, ans = 0, z = 0, o = 1;
vpll flag, D; vll path;
//***********//
int main() {
	cin >> N;
	vl A(3*N);
	for (i = 0; i < 3*N; i++) cin >> A[i];
	vl sum(3*N+1);
	multiset<ll> S;
	for (i = 0; i < N; i++) {
		S.insert(A[i]);
		sum[i + 1] = sum[i] + A[i];
	}
	for (i = N; i < 3*N; i++) {
		sum[i + 1] = sum[i];
		if (A[i] > *S.begin()) {
			sum[i + 1] += A[i] - *S.begin();
			S.erase(S.begin());
			S.insert(A[i]);
		}
	}
	//debug(sum);
	vl sum2(3 * N + 1);
	multiset<ll> S2;
	sum2[3 * N] = -A[3 * N - 1];
	S2.insert(-A[3*N-1]);
	for (i = 3*N-2; i >=2*N; i--) {
		S2.insert(-A[i]);
		sum2[i+1] = sum2[i+2] - A[i];
	}
	for (i = 2*N-1; i >= 0; i--) {
		sum2[i + 1] = sum2[i+2];
		if (-A[i] > *S2.begin()) {
			sum2[i + 1] += -A[i] - *S2.begin();
			S2.erase(S2.begin());
			S2.insert(-A[i]);
		}
	}
	//debug(sum2);
	ans = -INF;
	for (i = N; i <= 2*N; i++) {
		ans = max(ans, sum[i] + sum2[i + 1]);
	}
	cout << ans;
}