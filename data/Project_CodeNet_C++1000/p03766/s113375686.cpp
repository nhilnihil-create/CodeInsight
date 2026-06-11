#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <time.h>
#define int long long
#define endl '\n'
#define INF 1000000000000000000
#define EPS 1e-10
#define all(a) a.begin(),a.end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define fi first
#define se second
#define pb push_back
#define double long double
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;
template<class T, class S> bool chmax(T &a, const S &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T, class S> bool chmin(T &a, const S &b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll n, ll m) { return (m ? gcd(m, n%m) : n); }
ll lcm(ll n, ll m) { return n / gcd(n, m)*m; }

ll mod = 1000000007;
int dp[1000010];
int sum[1000010];

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	//modcalc();

	int n;
	cin >> n;
	dp[0] = 1; sum[0] = 1;
	dp[1] = n; sum[1] = n + 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = (n - 1)*(n - 1);
		dp[i] += dp[i - 1];
		dp[i] %= mod;
		int l = i - n - 1, r = i - 3;
		if (r <= 0) {
			dp[i] += n - 1;
		}
		else if (l <= 0) {
			dp[i] -= l;
			dp[i] += sum[r];
		}
		else {
			dp[i] -= sum[l - 1];
			dp[i] += sum[r];
		}
		dp[i] = (dp[i] + mod) % mod;
		sum[i] = (sum[i - 1] + dp[i]) % mod;
	}
	cout << dp[n] << endl;
}