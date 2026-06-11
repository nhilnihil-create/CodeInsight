#include<bits/stdc++.h>
#define mod 1000000007
#define N 2000009
#define ad(x,y) (x=(x+(y))%mod)
using namespace std;

int n,dp[N],sum[N];
int calc(int l,int r){
	l=max(0,l); r=min(r,n-2);
	if (l<=r) return l?(sum[r]-sum[l-1]+mod)%mod:sum[r];
	else return 0;
}
int main(){
	scanf("%d",&n);
	int i,ans=(n-1+(long long)(n-1)*(n-2))%mod;
	dp[0]=sum[0]=1;
	for (i=1; i<=(n<<1); i++){
		ad(dp[i],dp[i-1]);
		ad(dp[i],calc(i-n-1,i-3));
		sum[i]=(sum[i-1]+dp[i])%mod;
		if (i<n) ad(ans,(long long)dp[i]*(n-1));
		if (i+1<n) ad(ans,(long long)dp[i]*(n-1)%mod*(n-2));
	}
	printf("%d\n",(ans+dp[n<<1])%mod);
	return 0;
}
