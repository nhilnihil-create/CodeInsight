#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <math.h>
#include <list>
#include <numeric>

using namespace std;

#define Rep(i,a,b) for(int i = a; i < b; i++)
#define rep(i,b) Rep(i,0,b)
#define rrep(i,a) for(int i = a; i >= 0; i--)
#define allof(a) (a).begin(), (a).end()

typedef long long ll;
const int inf = 1e9 + 7;
const ll infll = 1ll << 60ll;
const ll mod = 1e9 + 7;
// 0~3までは右左下上 4~7までは斜め
constexpr int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
constexpr int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1 };

/*
// 最大公約数
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

// 最小公倍数
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}*/

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n, W;
	cin >> n >> W;
	vector<ll> w(n), v(n);
	ll baseWeight = inf;
	rep(i, n) {
		cin >> w[i] >> v[i];
		baseWeight = min(baseWeight, w[i]);
	}
	// w1 <= wi <= w1 + 3
	// wは4パターンしか値を持たない

	ll maxW = accumulate(allof(w), 0);
	if (maxW <= W) {
		cout << accumulate(allof(v), 0) << endl;
		return 0;
	}

	// wsumの取りうる値は？
	// w1 * i <= wsum <= (w1 + 3) * i
	rep(i, n) {
		w[i] -= baseWeight;
	}
	maxW -= baseWeight * n;
	// dp[i][j][k] := i番目までの商品を見て重さがjでありk個選んだ時の価値
	vector<vector<vector<ll>>> dp(100 + 10, vector<vector<ll>>(500 + 10, vector<ll>(100 + 10, -1)));
	rep(i, 110) {
		dp[i][0][0] = 0;
	}

	rep(i, n) {
		rep(j, 510) {
			rep(k, n) {
				if (j - w[i] >= 0 && k < n) {
					dp[i + 1][j][k + 1]  = max(dp[i + 1][j][k + 1], dp[i][j - w[i]][k] + v[i]);
				}
				dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
			}
		}
	}

	ll ans = 0;
	rep(i, n + 1) {
		for (ll j = 509; j >= 0; j--) {
			rep(k, n + 1) {
				if (dp[i][j][k] != -1 && j + (ll)k * baseWeight <= W) {
					ans = max(ans, dp[n][j][k]);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
