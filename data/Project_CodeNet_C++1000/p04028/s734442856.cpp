#include<bits/stdc++.h>
using namespace std;
#define ll long long
const long long mod=1e9+7;
ll pow(ll a, ll b, ll MOD)
{
 ll x=1,y=a; 
 while(b > 0)
 	{
 		if(b%2 == 1)
 	{
 		x=(x*y);
 		if(x>MOD) x%=MOD;
 	}
 	y = (y*y);
 	if(y>MOD) y%=MOD; 
 	b /= 2;
 	}
 return x;
}
 
long long dp[5001][5001],n,l;
int main(){
	cin>>n;
	string s;
	cin>>s;	l=s.size();
	dp[0][0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<=n;j++){
			if(dp[i][j]){
				dp[i+1][j+1]+=2*dp[i][j];
				dp[i+1][j+1]%=mod;
				if(j==0){
					dp[i+1][0]+=dp[i][0];
					dp[i+1][0]%=mod;
				}
				else{
					dp[i+1][j-1]+=dp[i][j];
					dp[i+1][j-1]%=mod;
				}
			}
		}
	}
	cout<<dp[n][l]*pow(pow(2,l,mod),mod-2,mod)%mod;
}