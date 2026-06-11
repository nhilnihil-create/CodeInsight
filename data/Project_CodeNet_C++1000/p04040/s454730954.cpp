#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,A,B,ans,p=1e9+7,jc[500001],ny[500001];
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
	ll i,j,x,y,sz;
	scanf("%lld%lld%lld%lld",&n,&m,&A,&B);
	jc[0]=ny[0]=1;
	for(i=1;i<=n+m;i++)jc[i]=jc[i-1]*i%p;
	ny[n+m]=ksm(jc[n+m],p-2);
	for(i=n+m-1;i;i--)ny[i]=ny[i+1]*(i+1)%p;
	ans=C(n+m-2,n-1);
	for(i=1;i<=A;i++){
		x=i;y=m-B;
		sz=C(x+y-2,x-1);
		x=n-i+1;y=m-y;
		sz=sz*C(x+y-2,x-1)%p;
		ans=(ans-sz+p)%p;
	}
	printf("%lld",ans);
}