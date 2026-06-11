#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,popcnt,sse4.1,sse4.2,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 105, mod = 1e9 + 7;
const ld tau = 6.28318530717958647692;
const ld A = 2.5*tau - 20.;
const ld B = 5.0*tau - 20.;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll q, h, s, d, n;
	cin >> q >> h >> s >> d >> n;
	h = min(h, 2*q);
	s = min(s, 2*h);
	d = min(d, 2*s);
	cout << (n/2)*d + (n&1)*s;
}
