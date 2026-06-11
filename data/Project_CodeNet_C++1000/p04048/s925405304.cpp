#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
#define rep(i,a,b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef complex<double> com;
const int mod = 1e9 + 7;
const int MOD = 998244353;
const int inf = 2e9;

ll gcd(ll a, ll b) {
	if (a % b == 0) return b;
	else return gcd(b, a % b);
}

int main() {
	ll n, x; cin >> n >> x;
	printf("%lld", 3LL * (n - gcd(n, x)));
	return 0;
}
