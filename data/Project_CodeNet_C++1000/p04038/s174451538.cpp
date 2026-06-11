#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,f[2010][2010],jc[4000010],ny[4000010],p=1e9+7;
ll C(ll x,ll y){
	return jc[x]*ny[y]%p*ny[x-y]%p;
}
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
	scanf("%lld%lld",&n,&m);
	if(m==1)return puts("1"),0;
	jc[0]=1;ny[0]=ny[1]=1;
	for(i=1;i<=n*m;i++)jc[i]=jc[i-1]*i%p;
	ny[n*m]=ksm(jc[n*m],p-2)%p;
	for(i=n*m-1;i>=2;i--){
	 ny[i]=ny[i+1]*(i+1)%p;
	 //printf("%lld %lld %lld\n",i,jc[i],ny[i]);
}
	for(i=0;i<=n;i++)f[i][0]=1;
	for(i=1;i<=n;i++){
		for(j=1;j<=i;j++){
			f[i][j]=f[i-1][j];
			f[i][j]=(f[i][j]+f[i][j-1]*(n-j+1)%p*C(n*m-i-(j-1)*(m-1)-1,m-2))%p;
			//printf("%lld %lld %lld %lld %lld %lld\n",i,j,f[i][j],f[i-1][j],n*m-i-(j-1)*(m-1)-1,C(n*m-i-(j-1)*(m-1)-1,m-2));
		}
	}
	printf("%lld",f[n][n]);
}
/*
没有想到把当前放的固定在原序列上 
*/