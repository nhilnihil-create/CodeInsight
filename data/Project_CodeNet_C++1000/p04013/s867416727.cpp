#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <stdio.h>
#include <tuple>
#include <bitset>
#include <cfloat>
#include <fstream>
#include <limits.h>
#include <list>
#include <math.h>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <numeric>
#include <utility>
#include <sstream>

template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

using namespace std;
#define int long long
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define FORR(i,a,b)for(ll i=(a);i<=(b);i++)
#define repr(i,n) for(ll i=n;i>=0;i--)
#define P pair<ll, ll>
#define sz(x) (ll)x.size()
#define ALL(x) (x).begin(),(x).end()
#define ALLR(x) (x).rbegin(),(x).rend()
#define VE vector<ll>
#define COUT(x) cout<<(x)<<endl
#define MA map<ll,ll>
#define SE set<ll>
#define PQ priority_queue<ll>
#define PQR priority_queue<ll,VE,greater<ll>>
#define COUT(x) cout<<(x)<<endl
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define EPS (1e-10)
ll gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	if (b == 0) return a;
	return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	ll g = gcd(a, b);
	return a / g * b;
}
bool prime(ll n) {
	for (ll i = 2; i <= sqrt(n); i++) {
		if (n%i == 0)return false;
	}
	return n != 1;
}


const long long MOD = 1000000007;
const long long INF = 1LL << 60;


const int MAX_N = 100010;
// x_1,...,x_j から k 枚選んで x_i の合計を s にするような選び方の総数
int dp[55][55][2510];
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// 気づきにくいポイント
	// 解法: DP
	// ただしX = max{x_1,...,x_n,a}とおく。
	int n, a; cin >> n >> a;
	VE x(n); rep(i, n)cin >> x[i];
	int X = 0;
	rep(i, n)chmax(X, x[i]);
	chmax(X, a);
	for (int j = 0; j <= n; j++) {
		for (int k = 0; k <= n; k++) {
			for (int s = 0; s <= X * n; s++) {
				if (j == 0 && k == 0 && s == 0) {
					dp[j][k][s] = 1;
				}
				else if (j >= 1 && s < x[j - 1]) {
					dp[j][k][s] = dp[j - 1][k][s];
				}
				else if (j >= 1 && k >= 1 && s >= x[j - 1]) {
					dp[j][k][s] = dp[j - 1][k][s] + dp[j - 1][k - 1][s - x[j - 1]];
				}
				else {
					dp[j][k][s] = 0;
				}
			}
		}
	}
	int ans = 0;
	for (int k = 1; k <= n; k++) {
		ans += dp[n][k][k*a];
	}
	cout << ans << endl;
	return 0;
}