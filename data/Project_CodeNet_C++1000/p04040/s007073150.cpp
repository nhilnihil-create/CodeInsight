#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll p=1e9+7;
ll h,w,A,B,ans,jc[500010],ny[500010];
ll ksm(ll x,ll y){
	ll xlh=1;
	while(y){
		if(y&1)xlh=xlh*x%p;
		x=x*x%p;
		y/=2;
	}
	return xlh;
}
ll C(ll x,ll y){
	return jc[x]*ny[y]%p*ny[x-y]%p;
}
int main(){
	ll i,xlh;
	jc[0]=ny[0]=1;
	for(i=1;i<=200000;i++)jc[i]=jc[i-1]*i%p,ny[i]=ksm(jc[i],p-2);
	scanf("%lld%lld%lld%lld",&h,&w,&A,&B);
	ans=C(h-1+w-1,h-1);
	for(i=1;i<=B;i++){
		xlh=C(h-A-1+i-1,i-1)*C(A-1+w-i,A-1)%p;
		ans=(ans-xlh+p)%p;
	}
	printf("%lld",ans);
}