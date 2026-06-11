#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll p=1e9+7;
char s[5010];
ll n,m,i,j,f[5010][5010];
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
	scanf("%lld",&n);
	scanf("%s",s+1);
	m=strlen(s+1);
	f[0][0]=1;
	for(i=0;i<n;i++)
	 for(j=0;j<=i;j++){
	 	f[i+1][j+1]=(f[i+1][j+1]+f[i][j]*2%p)%p;
	 	if(j)f[i+1][j-1]=(f[i+1][j-1]+f[i][j])%p;
	 	 else f[i+1][0]=(f[i+1][0]+f[i][0])%p;
	 }
	//for(i=1;i<=n;i++)
	// for(j=0;j<=i;j++)printf("%d %d %d\n",i,j,f[i][j]);
	printf("%lld",(ll)f[n][m]*ksm(ksm(2,m),p-2)%p);
}
/*
0和1是等价的。。
然后直接f[i][j]表示i次按了j个即可。。
最后把答案除以2^n...... 
*/