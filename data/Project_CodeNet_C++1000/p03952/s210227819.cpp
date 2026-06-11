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
using vs = vector<string>; using tll = tuple<ll, ll, ll>; using vtll = vector<tll>;
const ld PI = 3.1415926535897932;
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define rep1(n) for(ll i=0;i<n;++i)
#define rep2(i,n) for(ll i=0;i<n;++i)
#define rep3(i,a,b) for(ll i=a;i<b;++i)
#define rep4(i,a,b,c) for(ll i=a;i<b;i+=c)
#define rep(...) overload4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)
#define mp make_pair
#define mt make_tuple
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
ll i, j, k, l; ll N, M, K, H, W, L, X, Y, Z, R, Q;
ll MOD = 1000000007; ll INF = 1LL << 60; ll ans = 0; ll z = 0, o = 1;
vl flag; vector<vpll> path, path2; vl D1, D2;
//***********//
int main() {
	cin >> N >> X;
	if (X == 1 || X == 2 * N - 1) cout << "No" << endl;
	else {
		cout << "Yes" << endl;
		if (N > 2) {
			vl Ans(2 * N - 1);
			vl used(2 * N + 1000000);
			if (X == 2) {
				Ans[N - 2] = 3;
				Ans[N - 1] = 2;
				Ans[N] = 1;
				Ans[N + 1] = 4;
				used[1] = 1; used[2] = 1; used[3] = 1; used[4] = 1;
			}
			else {
				Ans[N - 2] = X - 1;
				Ans[N - 1] = X;
				Ans[N] = X + 1;
				Ans[N + 1] = X - 2;
				used[X - 1] = 1; used[X] = 1; used[X + 1] = 1; used[X - 2] = 1;
			}
			ll now = 1;
			for (i = 0; i < 2 * N - 1; i++) {
				if (Ans[i] != 0) cout << Ans[i] << endl;
				else {
					while (true) {
						if (!used[now]) break;
						now++;
					}
					cout << now << endl;
					used[now] = 1;
				}
			}
		}
		else {
			cout << 1 << endl << 2 << endl << 3 << endl;
		}
	}
}