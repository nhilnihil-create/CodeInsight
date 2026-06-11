#include <bits/stdc++.h>
#define nmax 1000005

using namespace std;

const int mod = 1e9+7;

int dp[nmax], sdp[nmax], smdp[nmax];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n; cin >> n;
	
	dp[n-1]=n-1;
	sdp[n-1]=n-1;
	smdp[n-1]=(1ll*(n-1)*(n-1))%mod;
	
	for(int i=n-2;i>=0;i--){
		dp[i]=(1ll*(n-1)*n)%mod;
		
		if(i<n-3){
			dp[i]=(dp[i]+smdp[i+3])%mod;
			dp[i]=(dp[i]-1ll*(i+2)*sdp[i+3])%mod;
			if(dp[i]<0)
				dp[i]+=mod;
		}
		
		sdp[i]=(dp[i]+sdp[i+1])%mod;
		smdp[i]=(1ll*dp[i]*i+smdp[i+1])%mod;
	}
	
	cout << (sdp[0]+1)%mod << endl;
	return 0;
}