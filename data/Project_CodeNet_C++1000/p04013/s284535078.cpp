# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
# define MOD 1000000007
using namespace std;

int n,k;
int N=10;


int main(){
	fastio;
	cin>>n>>k;
	vector<int> a(n);
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(n+1,vector<ll>(k*n+1,0)));
	dp[0][0][0]=1;
	for (int i=1;i<=n;i++){
		dp[i][0][0]=1;
		for(int j=1;j<=i;j++){
			for (int x=k*n;x>=1;x--){
				dp[i][j][x]=dp[i-1][j][x];
				if (x>=a[i-1])
				dp[i][j][x]+=dp[i-1][j-1][x-a[i-1]];
				// cout<<i<<' '<<j<<' '<<x<<' '<<dp[i][j][x]<<'\n';
			}
		}
	}
	ll re=0;
	for (int j=1;j<=n;j++){
		re+=dp[n][j][k*j];
		// cout<<re<<' ';
	}
	cout<<re<<'\n';
	return 0;
}