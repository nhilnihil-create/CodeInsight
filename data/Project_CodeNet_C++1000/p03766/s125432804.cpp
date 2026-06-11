//khodaya khodet komak kon
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#pragma GCC optimise ("ofast")
#pragma GCC optimise("unroll-loops")
#define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1000000 + 10;
const ll MOD = 1000000000 + 7;
const ll INF = 1000000000000000000;
const ll LOG = 25;

int n, dp[2 * N], Sum, ps[2 * N];

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 2 * n; i >= n + 1; i--) dp[i] = 1, ps[i] = 1 + ps[i + 1];
	dp[n] = n;
	ps[n] = ps[n + 1] + dp[n];
	//cout << ps[n] << '\n';
	for (int i = n - 1; i >= 1; i--){
		dp[i] += dp[i + 1];
		//cout << ps[i + n + 1] << ' ' << ps[i + 2] << '\n';
		ll res = ps[i + 3] - ps[i + n + 2];
		res %= MOD;
		res += MOD;
		res %= MOD;
		//cout << dp[i] << ' ';
		dp[i] += res;
		//cout << dp[i] << '\n';
		dp[i] %= MOD;
		dp[i] += (n - 1) * (n - 1) % MOD;
		dp[i] %= MOD;
		ps[i] = ps[i + 1] + dp[i];
		ps[i] %= MOD;
	}
	cout << dp[1];











	return 0;
}
