#include<iostream>
#include<cstdio>
#define mod 1000000007
#define ll long long
using namespace std;

ll qpow(ll x,ll t){
	ll ans=1;
	while(t){
		if(t&1)ans=(ans*x)%mod;
		x=(x*x)%mod;
		t>>=1;
	}
	return ans%mod;
}

ll fac[200010],nf[200010],h,w,a,b,ans=0;

ll c(ll x,ll y){
	return (((fac[y]*nf[x])%mod)*nf[y-x])%mod;
}

int main(){
	
	fac[0]=1;
	for(ll i=1;i<=200001;i++)
		fac[i]=(fac[i-1]*i)%mod;
	for(ll i=0;i<=200001;i++)
		nf[i]=qpow(fac[i]%mod,mod-2)%mod;
	
	cin>>h>>w>>a>>b;
	
	for(ll i=h-a,j=b+1;i>=1&&j<=w;i--,j++){
//		cout<<i<<" ! "<<j<<endl;
		ans=(ans+mod+((c(i-1,i+j-2)%mod)*(c(h-i,w+h-j-i)%mod))%mod)%mod;
	}
	
	cout<<ans;
}