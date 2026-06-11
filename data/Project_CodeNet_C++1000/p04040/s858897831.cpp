#include<iostream>
using namespace std;
#define ll long long
const ll mod=1e9+7;
ll qm(ll a,ll b){
    ll res=1;
    while(b>0){
        if(b&1)res=res*a%mod;b>>=1;a=a*a%mod;
    }
    return res;
}
ll fac[500000];
ll inv[500000];
void init(){
    fac[0]=fac[1]=inv[0]=inv[1]=1;
    for(int i=2;i<500000;++i)fac[i]=fac[i-1]*i%mod;
    inv[499999]=qm(fac[499999],mod-2);
    for(int i=499998;i>1;--i){
        inv[i]=inv[i+1]*(i+1)%mod;
    }
}
ll C(int n,int m){
    if(m==0||n==m)return 1;
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int main()
{
	init();
	int n,m,a,b;
	cin>>n>>m>>a>>b;
	ll ans=C(n-1+m-1,n-1);
	for(int i=1;i<=b;++i){
        ll ty=C(abs(n-a-1)+abs(1-i),abs(n-a-1));
        ll tu=C(abs(1-a)+abs(m-i),abs(1-a));
        ty=ty*tu%mod;
        ans-=ty;
        ans=(ans%mod+mod)%mod;
	}
	 cout<<ans<<endl;
	return 0;
}
