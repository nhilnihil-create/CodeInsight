#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1000000000
#define MOD 1000000007
#define MAXN 1000010

ll n;
ll dp[2*MAXN];

int main(){
		//for(n=1; n<=1000000; n++){
		n=2;
		scanf("%lld", &n);
		ll sum = n-1;
		for(int i=2*n; i>=0; i--){
			if(i>=n){
				dp[i] = 1;
			}
			else if(i==n-1){
				dp[i] = n;
			}
			else{
				dp[i] = ((n-1)*(n-1)+ dp[i+1])%MOD;
				/*for(int j=2; (j<=n); j++){
					if(i+j+1>=n) dp[i] = (dp[i]+1)%MOD;
					else dp[i] = (dp[i] + dp[i+j+1])%MOD;	
				}*/
				dp[i] = (dp[i] + sum)%MOD;	
				sum = (sum - dp[n+i+1] + MOD)%MOD;
				sum = (sum + dp[i+2])%MOD;
			}
		}
		printf("%d\n", dp[0]);
	//}
	return 0;
}
