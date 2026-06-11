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

ll f(ll b, ll n) {
	if (n < b) { return n; }
	return f(b, n / b) + n % b;
}


int main() {

	ll N, A;
	cin >> N >> A;

	ll dp[51][51][3000] = {};
	dp[0][0][0] = 1;

	repn(i, N) {
		ll x;
		cin >> x;

		dp[i][0][0] = 1;

		repn(j, N) {

			rep(k, 3000) {
				if (k < x) { dp[i][j][k] = dp[i - 1][j][k]; }
				else { dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k - x]; }
			}
		}
	}

	ll ans = 0;

	repn(i, N) {
		ans += dp[N][i][i*A];
	}
	cout << ans;

	system("PAUSE");
}
