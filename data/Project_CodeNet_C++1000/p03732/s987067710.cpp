#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 105;
const int M = 305;
int w[N], v[N], dp[N][N][M];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n, W;
	cin>>n>>W;
	for(int i = 1; i <= n; i++){
		cin>>w[i]>>v[i];
	}
	int base_w = w[1];
	for(int i = 1; i <= n; i++){
		w[i] -= base_w;
	}
	int ans = 0;
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			if(j*base_w > W)break;
			for(int sum = 0; sum < M; sum++){
				if(j*base_w + sum > W)continue;
				dp[i][j][sum] = dp[i - 1][j][sum];
				if(sum >= w[i])dp[i][j][sum] = max(dp[i][j][sum], dp[i - 1][j - 1][sum - w[i]] + v[i]);
				ans = max(ans, dp[i][j][sum]);
				// cout<<i<<" "<<j<<" "<<sum + j*base_w<<" "<<dp[i][j][sum]<<'\n';
			}
		}
	}
	cout<<ans<<'\n';


	return 0;
}