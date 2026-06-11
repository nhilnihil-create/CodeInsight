#include <bits/stdc++.h>
#define bp __builtin_popcountll
#define pb push_back
#define in(s) freopen(s, "r", stdin);
#define out(s) freopen(s, "w", stdout);
#define inout(s, end1, end2) freopen((string(s) + "." + end1).c_str(), "r", stdin),\
		freopen((string(s) + "." + end2).c_str(), "w", stdout);
#define fi first
#define se second
#define bw(i, r, l) for (int i = r - 1; i >= l; i--)
#define fw(i, l, r) for (int i = l; i < r; i++)
#define fa(i, x) for (auto i: x)
using namespace std;
const int mod = 1e9 + 7, inf = 1061109567;
const long long infll = 4557430888798830399;
const int N = 1e5 + 5;
int n, p[N], dp[N][2];
signed main() {
	#ifdef BLU
	in("blu.inp");
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//bad - bad => a swap makes good - good. bad - good also does the same.
	//dp(i, 2): ith element, i is swapped with i - 1 or not.
	cin >> n;
	fw (i, 0, n) cin >> p[i], p[i]--;
	memset(dp, 63, sizeof dp);
	dp[0][0] = 0;
	fw (i, 1, n) {
		if (p[i] == i) dp[i][1] = min(dp[i - 1][1], dp[i - 1][0]) + 1;
		else {
			//If i - 1 and i - 2 was swapped and at least 1 is bad => both are good after => no cause to use
			//it.
			if (p[i - 1] == i - 1) dp[i][1] = dp[i - 1][0] + 1;
		}
		
		dp[i][0] = dp[i - 1][1];
		if (p[i - 1] != i - 1) dp[i][0] = min(dp[i][0], dp[i - 1][0]);
	}
	if (p[n - 1] == n - 1) cout << dp[n - 1][1];
	else cout << min(dp[n - 1][0], dp[n - 1][1]);
	return 0;
}