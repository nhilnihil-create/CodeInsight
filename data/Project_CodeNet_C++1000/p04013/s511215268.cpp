#include<iostream>
#include<vector>
#include<cstring>

#define ll unsigned long long int

using namespace std;

ll dp[51][51][2501];
ll v[51];

ll a;

ll ways(ll n, ll cnt, ll sum) {

	if(n == 0) {

		if(cnt == 0)return 0;

		if(sum % cnt) return 0;

		if(sum/cnt != a) return 0;

		return 1;
	}

	if(dp[n][cnt][sum] != -1) return dp[n][cnt][sum];

	return dp[n][cnt][sum] = ways(n-1,cnt + 1, sum + v[n-1]) + ways(n-1,cnt, sum);
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll n; cin >> n >> a;
	memset(dp,-1,sizeof(dp));

	for(int i = 0; i < n; i++) cin >> v[i];

	ways(n,0,0);

	cout << dp[n][0][0] << '\n';

	return 0;
}