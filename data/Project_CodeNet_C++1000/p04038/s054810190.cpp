#include<bits/stdc++.h>
using namespace std;
const int N=2e3+7,p=1e9+7;
int n,k,dp[N][N]; long long fac[N*N],ifac[N*N];
inline int pows(long long u,int v){
	long long ans=1; while(v>0) {if(v&1) ans=ans*u%p; u=u*u%p,v=v>>1;} return ans;
}
inline long long getans(int a,int b){
	return fac[a]*ifac[b]%p*ifac[a-b]%p;
}
int main(){
	cin>>n>>k,fac[0]=ifac[0]=1;
	for(int i=1;i<=n*k;i++) fac[i]=fac[i-1]*i%p,ifac[i]=pows(fac[i],p-2); dp[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=i;j++){
			if(j>0) dp[i][j]=(dp[i][j-1]*getans(n*k-(k-1)*(j-1)-i-1,k-2)+dp[i-1][j])%p;
			else dp[i][j]=dp[i-1][j];
		}
	if(k==1) cout<<1<<endl; else cout<<dp[n][n]*fac[n]%p<<endl;
    return 0;
} 