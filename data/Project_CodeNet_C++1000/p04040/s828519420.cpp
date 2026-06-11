#pragma GCC optimize(2)
#include<bits/stdc++.h> 
using namespace std;
#define ll long long
#define endl "\n"
const int mod=1e9+7;
const int MAX=1e6+7;
ll f[MAX];
ll qpow(ll a,ll b,ll mod){
	ll res=1;
	for(;b;b>>=1){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
	}
	return res;
}
ll cal(ll n,ll m){
	if(n-m<m)m=n-m;
	return (f[n]*qpow(f[m]*f[n-m]%mod,mod-2,mod))%mod;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n,m,a,b;cin>>n>>m>>a>>b;
	f[0]=1;
	for(ll i=1;i<MAX-5;i++)
		f[i]=(f[i-1]*i)%mod;
	ll ans=0;
	for(ll i=b+1;i<=m;i++)
		ans=(ans+cal(n-a-1+i-1,n-a-1)*cal(a+m-i-1,a-1)%mod)%mod;
	cout<<(ans+mod)%mod;
   return 0;
} 