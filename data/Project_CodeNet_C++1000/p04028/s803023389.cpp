#include <bits/stdc++.h>
using namespace std ;
#define N 5010
#define ll long long
const int mod=1e9+7 ;
char s[N];
int f[N][N],n;
ll power(ll a,ll b){
	ll ans=1,base=a;
	while(b){
		if(b&1) ans=(ans*base)%mod ;
		base=(base* base)%mod;
		b/=2;
	}
	return ans%mod ;
}
int main(){
	scanf("%d%s",&n,s+1);
	int len=strlen(s+1) ;
	f[0][0]=1;
	for( int i=0;i<=n;i++) {
		for( int j=0;j<=i;j++){
			f[i+1][j+1]+=2*f[i][j];
			f[i+1][j+1]%=mod;
			f[i+1][max(j-1,0)]+=f[i][j];
			f[i+1][max(j-1,0)]%=mod ;
		}
	}
	ll ans=1ll*power(power(2,len),mod-2)%mod*f[n][len];
	ans%=mod;
	printf("%lld",ans);
	return 0 ;
} 