#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define dunk(a) cout << (a) << "\n"
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, a, b;
	cin >> n >> a >> b;
	vector<ll> x(n);
	rep(i, n) cin >> x[i];
	vector<ll> dp(n + 1);
	dp[0] = 0;
	rrep(i, n) {
		dp[i] = min(dp[i - 1] + b, dp[i - 1] + (x[i] - x[i - 1]) * a);
	}
	dunk(dp[n - 1]);
	return 0;
}