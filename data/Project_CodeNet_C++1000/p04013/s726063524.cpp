#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar array
#define pb push_back
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,a;
	cin>>n>>a;
	int x[n];
	for(int i = 0; i<n; i++) cin>>x[i];
	ll dp[2501][51];
	memset(dp,0,sizeof(dp));
	ll ans = 0;
	for(int i = 0; i<n; i++)
	{
		ll dp2[2501][51];
		memset(dp2,0,sizeof(dp2));
		for(int j = 1; j<=2500; j++)
		{
			for(int k = 0; k<n; k++)
				if(dp[j][k])
					dp2[j+x[i]][k+1]+=dp[j][k];
		}
		dp2[x[i]][1]++;
		for(int j = 1; j<=2500; j++)
			for(int k = 0; k<=n; k++)
					dp[j][k]+=dp2[j][k];
	}
	for(int j = 1; j<=n; j++)
		ans += dp[a*j][j];
	cout<<ans<<endl;
	return 0;
}