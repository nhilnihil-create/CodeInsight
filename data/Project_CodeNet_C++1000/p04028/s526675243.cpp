#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,f[5010][5010],p=1e9+7;
char s[5010];
ll ksm(ll x,ll y){
	ll xlh=1;
	while(y){
		if(y&1)xlh=xlh*x%p;
		x=x*x%p;
		y/=2;
	}
	return xlh;
}
int main(){
	ll i,j;
	scanf("%lld",&n);
	scanf("%s",s+1);
	m=strlen(s+1);
	f[0][0]=1;
	for(i=0;i<n;i++)
	 for(j=0;j<=i;j++){
	 //	printf("%lld %lld %lld\n",i,j,f[i][j]);
	 	f[i+1][j+1]=(f[i+1][j+1]+f[i][j]*2)%p;
	 	f[i+1][max(j-1,0ll)]=(f[i+1][max(j-1,0ll)]+f[i][j])%p;
	 }
	//for(i=0;i<=n;i++)printf("%lld ",f[n][i]);puts("");
	printf("%lld",f[n][m]*ksm(ksm(2,m),p-2)%p);
}