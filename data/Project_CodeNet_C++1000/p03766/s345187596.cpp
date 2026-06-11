#include<bits/stdc++.h>
using namespace std;
const int N=1e6+2;
const int mod=1e9+7;
int dp[N],sdp[N];
void add(int &x,int y){
	x+=y;
	if(x>=mod){
		x-=mod;
	}
}
int mul(int x,int y){
	return (1ll*x*y)%mod;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,i,j,k,l,ans=0;
	cin>>n;
	dp[0]=1;
	sdp[0]=1;
	for(i=1;i<=n;i++){
		add(dp[i],dp[i-1]);
		if(i>2){
			add(dp[i],sdp[i-3]);
		}
		sdp[i]=sdp[i-1];
		add(sdp[i],dp[i]);
	}
	for(i=1;i<=n;i++){
		if(i<n){
			add(dp[n],mul(dp[i-1],mul(n-1,n-1)));
		}
		add(dp[n],mul(dp[i-1],min(i,n-1)));
	}
	cout<<dp[n];
}