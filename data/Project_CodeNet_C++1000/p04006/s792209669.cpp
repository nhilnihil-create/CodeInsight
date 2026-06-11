#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#include <functional>
using namespace std;

#define rep(i,x) for(ll i=0;i<x;i++)
#define repn(i,x) for(ll i=1;i<=x;i++)

typedef long long ll;
const ll INF = 1e17;
const ll MOD = 1000000007;
const ll MAX = 1000001;

ll max(ll a, ll b) {
	if (a > b) { return a; }
	return b;
}

ll min(ll a, ll b) {
	if (a > b) { return b; }
	return a;
}

ll gcd(ll a, ll b) {
	if (b == 0) { return a; }
	if (a < b) { return gcd(b, a); }
	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

struct edge {
	ll ind;
	ll fr;
	ll to;
	ll d;
};


///////////////////////////




int main() {
	
	ll N,x;
	cin >> N>>x;
	vector<ll> A(N,0);
	rep(i, N) cin >> A[i];

	vector<vector<ll>> dp(N, vector<ll>(N + 1, 0));
	rep(i, N) dp[0][i] = A[i];

	ll ans = INF;

	repn(i, N - 1) {

		rep(j, N) {
			dp[i][j] = min(dp[i - 1][j], dp[i - 1][(j+N - 1)%N]);
		}
	}

	rep(i, N) {
		ll v = x * i;
		rep(j, N) { v += dp[i][j]; }
		ans = min(ans, v);
	}

	cout << ans;

	system("PAUSE");
}
