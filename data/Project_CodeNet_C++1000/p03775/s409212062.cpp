#ifdef __GNUC__
#pragma GCC target("avx2")
#pragma GCC optimize ("O20")
#pragma GCC optimize ("tree-vectorize")
#pragma GCC optimize("unroll-loops")
#define iss std::cin
#endif
#include "bits/stdc++.h"
#define rep(i, times) for(ll i = 0; i < (times); ++i)
#define pr(x) (cout << x << "\n")
using ll = int_fast64_t; using namespace std;

#ifndef __GNUC__
string text =
R"X(9876543210)X";
stringstream iss{text};
#endif

inline ll keta(ll n) { return ll(log10(n)) + 1; }
int main( ) {
	cin.tie(0);	ios::sync_with_stdio(0);
	ll N; iss >> N;
	ll minK{LLONG_MAX};
	ll sqN{ll(sqrt(N)) + 1};
	for (ll a = 1; a < sqN; ++a) {
		ll b = N / a;
		if (b * a == N) {
			minK = min(minK, keta(max(a, b)));
		}
	}
	pr(minK);
}