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
	return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) *b;
}

struct edge {
	ll ind;
	ll to;
	ll d;
};


///////////////////////////


int main() {

	ll N, W;
	cin >> N >> W;

	vector<ll> w(N + 1), v(N + 1);
	repn(i, N) cin >> w[i] >> v[i];

	ll ans = 0;

	rep(i,N+1){

		ll x = W - w[1] * i;
		x = min(x, 3 * N);
		if (x < 0) { continue; }

		ll dp[200][200][400] = {};

		repn(j, N)repn(k,N)rep(l, 3 * N + 1) {
			if (l < w[j] - w[1]) {
				dp[j][k][l] = dp[j - 1][k][l];
				continue;
			}
			dp[j][k][l] = max(dp[j - 1][k][l], dp[j-1][k - 1][l - (w[j] - w[1])] + v[j]);
		}

		ans = max(ans, dp[N][i][x]);

		
	}

	cout << ans;
	
	system("PAUSE");
}
