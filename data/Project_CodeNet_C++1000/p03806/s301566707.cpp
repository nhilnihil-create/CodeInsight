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

	ll N, ma, mb;
	cin >> N >> ma >> mb;

	ll dp[41][500][500];
	rep(i, 41)rep(j, 500)rep(k, 500) { dp[i][j][k] = INF; }

	dp[0][0][0] = 0;

	repn(i, N) {

		ll a, b, c;
		cin >> a >> b >> c;
		rep(j, 500)rep(k, 500) {
			if (j >= a && k >= b) {
				dp[i][j][k] = min(dp[i - 1][j][k], dp[i - 1][j - a][k - b] + c);
			}

			else { dp[i][j][k] = dp[i - 1][j][k]; }
		}
	}

	ll ans = INF;
	for (int i = 1; i*ma < 500 && i*mb < 500; i++) {
		ans = min(ans, dp[N][i*ma][i*mb]);
	}

	if (ans == INF) { cout << -1; }
	else { cout << ans; }


	system("PAUSE");
}