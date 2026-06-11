#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
const int mod=1e9+7;
ll n,m,a,b;
ll ksm(ll a,ll b){
	ll res=1,t=a;
	while(b){
		if(b&1)res=(res*t)%mod;
		t=(t*t)%mod;
		b>>=1;
	}
	return res;
}
ll jc[N],inv[N];
void init(){
	jc[0]=inv[0]=1;
	for(int i=1;i<N;i++)jc[i]=(jc[i-1]*i)%mod,inv[i]=ksm(jc[i],mod-2);
}
ll C(ll a,ll b){
	return ((jc[b]*inv[a])%mod*inv[b-a])%mod;
}
int main()
{
	//freopen("H:\\c++1\\in.txt","r",stdin);
	//freopen("H:\\c++1\\out.txt","w",stdout);
	init();
	scanf("%lld%lld%lld%lld",&n,&m,&a,&b);
	ll ans=0;
	for(int i=1;i<=n-a;i++){
		ll ans1=C(b-1,b+i-2);
		ll ans2=C(m-b-1,n-i+m-b-1);
		ans=(ans+ans1*ans2)%mod;
	}
	printf("%lld\n",ans);
	return 0;
}