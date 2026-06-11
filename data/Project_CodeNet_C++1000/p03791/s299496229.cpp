#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <functional>
#include <cmath>
#include <complex>
#include <cctype>
#include <cassert>
#include <sstream>
 
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
 
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> p;

#define INF (1<<29)
#define INFL (1ll<<60)
#define EPS (1e-10)
#define PI (acos(-1))
const ll MOD = 1000000007ll;


ll mod_pow(ll x, ll n) {
	if (n == 0) return 1;
	ll res = mod_pow(x * x % MOD, n / 2);
	if (n & 1) res = res * x % MOD;
	return res;
}

ll n;
ll x[112345];
ll fact[112345];

int main() {
	cin >> n;
	REP(i, n) scanf("%lld", x + i);
	
	fact[0] = 1;
	FOR(i, 1, 112345) fact[i] = fact[i - 1] * i % MOD;
	
	ll ans = 1, cnt = 0;
	FOR(i, 1, n) {
		if (x[i] < (i - cnt) * 2 + 1) {
			ans = ans * (i + 1 - cnt) % MOD;
			cnt++;
		}
	}
	ans = ans * fact[n - cnt] % MOD;
	
	cout << ans << endl;
	return 0;
}
