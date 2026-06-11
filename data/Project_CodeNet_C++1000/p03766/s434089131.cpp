#include <bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1000000007;

int sq(int n) {
	return (n*n) % M;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	// sequence is mostly 1
	// two non-1s consecutive --> sequence terminates
	// operations:
	// place 1 --> place anything next --> 1 way to
	// place k > 1
	//		--> jump to i+k, placing full 1 along the way --> 1 way
	//		--> jump to INF, placing a non-1 value --> (n-1) ways
	// O(N^2) dp --> how to O(N)?
	// at position n --> can place anything --> still terminates --> n ways
	// at position > n --> consider to be terminated --> n+3
	// terminate at position n and > n
	// ans = dp[n]*n + dp[n+3]
	
	int n; cin >> n;
	vector<int> dp(n+5);
	dp[0] = 1; dp[1] = M - 1;
	for (int i = 0; i <= n; i++) {
		if (i) dp[i] += dp[i-1];
		dp[i] %= M;
		if (dp[i] < 0) dp[i] += M;
		
		int val = dp[i];
		// at n --> terminates placing anything
		if (i == n) {
			break;
		}
		
		// one way to reach the next
		dp[i+1] = (dp[i+1] + val) % M;
		dp[i+2] = (dp[i+2] - val) % M;
		
		if (!i) continue;
		
		// one way to reach each of min(i+2+1, n) using 1 --> sum n-1
		int reachable = max(0LL, n - (i+2));
		int inf_reach = (n-1) - reachable;
		
		dp[i+3] = (dp[i+3] + val) % M;
		dp[n+1] = (dp[n+1] - val) % M;
		
		dp[n+3] = (dp[n+3] + val*inf_reach) % M;
		
		// terminate immediately --> (n-1)*(n-1) ways
		dp[n+3] = (dp[n+3] + val*sq(n-1)) % M;
	}
	
	for (int i = 1; i <= n; i++) {
		//cout << dp[i] << ' ';
	}
	//cout << dp[n+3] << '\n';
	
	cout << (dp[n]*n + dp[n+3]) % M << '\n';

	return 0;
}