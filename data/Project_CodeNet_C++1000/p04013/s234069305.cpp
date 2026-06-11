#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define l long
#define pb push_back
#define mp make_pair
#define mt make_tuple
ll dp[51][51][2525];
	
int main() {
	// your code goes here
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
	
	int n,A; cin>>n>>A;
	ll a[n+1];
	for(int i=1;i<=n;i++) cin>>a[i];
	
	for(int i=0;i<=n;i++)
	{
	    for(int j=0;j<=i;j++)
	    {
	        if(i==0 || j==0){ dp[i][j][0]=1; continue; }
	        for(int k=0;k<=n*50;k++)
	        {
	            if(k>=a[i])
	            {
	                dp[i][j][k] = dp[i-1][j-1][k-a[i]];
	            }
	            dp[i][j][k] += dp[i-1][j][k];
	           // if(k<=20)
	           //     cout<<i<<":"<<j<<":"<<k<<":"<<dp[i][j][k]<<'\n';
	        }
	    }
	}
	ll ans = 0;
	for(int i=1;i<=n;i++)
	{
	    //cout<<i<<":"<<dp[n][i][A*i]<<'\n';
	    ans += dp[n][i][A*i];
	}    
	cout<<ans;    
	
	return 0;
}
