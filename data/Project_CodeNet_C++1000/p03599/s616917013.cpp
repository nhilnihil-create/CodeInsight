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
//gcdlcm, isPrime, eratos, divisor, modinv, bitSearch, bitList, dfs, bfs//
//dijkstra, UnionFind, COM, digitDP//
ll i, j, k, l; ll N, M, K, H, W, L, X, Y, Z;
ll MOD = 1000000007; ll INF = 9999999999999; ll ans = 0;
vl flag, color, D; vll path;
//***********//
int main() {
	long double A, B, C, D, E, F;
	cin >> A >> B >> C >> D >> E >> F;
	long double sum = 0, suger = 0, P = 0;
	for (long double i = 0; i <= F/(100*A); i++) {
		for (long double j = 0; j <= (F-A*i)/(100*B); j++) {
			for (long double k = 0; k <= (F-A*100*i-B*100*j)/C ; k++) {
				for (long double l = 0; l <= (F - A * 100 * i - B * 100 * j - C * k) / D; l++) {
					long double w = 100 * A * i + 100 * B * j;
					long double s = C*k + D*l;
					if (s > E * (w/100)) continue;
					else if (s == 0) continue;
					else if ((100 * s) / (w + s) > P) {
						P = (100 * s) / (w + s);
						sum = w + s;
						suger = s;
					}
					//debug(w, s, P);
				}
			}
		}
	}
	if (P == 0) {
		cout << 100 * A << " " << suger;
	}
	else {
		cout << sum << " " << suger;
	}
}