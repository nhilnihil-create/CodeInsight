#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD=1000000007LL;
LL dp[1000001]; //dp[i]::=i番目以降の決め方
int main() {
	LL n;
	cin>>n;
	dp[n]=n;
	LL sum=n-1,add=((n-1)*(n-1))%MOD;
	for(int i=n-1;i>=1;i--) {
		dp[i]=(dp[i+1]+add+sum)%MOD;
		sum=(sum+MOD-1)%MOD;
		if(i+2<=n) sum=(sum+dp[i+2])%MOD; else sum=(sum+1)%MOD;
	}
	cout<<dp[1]<<endl;
}