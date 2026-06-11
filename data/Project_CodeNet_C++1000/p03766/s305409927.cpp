#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1100000000

int main(){
	
	int n;
	cin>>n;
	
	if(n==1)cout<<1<<endl;
	else if(n==2)cout<<4<<endl;
	else{
		vector<int> dp(n+1,0),sum(n+1,0);
		dp[0] = 1;
		sum[0] = 1;
		for(int i=1;i<=n;i++){
			dp[i] = sum[i-1];
			if(i!=1)dp[i] = mod(dp[i] - dp[i-2]);
			sum[i] = mod(sum[i-1] + dp[i]);
		}
		int ans = 0;
		ans = dp.back();
		ans = mod(ans + mod(dp[n-1]*(n-1)));
		for(int i=n-2;i>=0;i--){
			int k = 1+i;
			ans = mod(ans + mod(dp[i] * mod((n-k-1)*(n-1))));
			ans = mod(ans + mod(dp[i] * mod(k * n)));
			
		}
		
		
		cout<<ans<<endl;
	}
	
	return 0;
}