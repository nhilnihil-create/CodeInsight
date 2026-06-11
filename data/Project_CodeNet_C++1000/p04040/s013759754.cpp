//c problem
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=200000+10;
const int mod=1e9+7;
ll n,m,a,b;
ll quick(ll a,ll b,ll mod){
	ll res=1,t=a;
	while(b){
		if(b&1)res=(res*t)%mod;
		t=(t*t)%mod;
		b>>=1;
	}
	return res;
}
ll jie[N],inv[N];
void chu(){
	jie[0]=inv[0]=1;
	for(int i=1;i<N;i++)jie[i]=(jie[i-1]*i)%mod,inv[i]=quick(jie[i],mod-2,mod);
}
ll c(ll a,ll b){
	return ((jie[b]*inv[a])%mod*inv[b-a])%mod;
}
int main()
{
	chu(); 
	ll a,b,n,m;
	cin>>n>>m>>a>>b; 
	ll ans=0;
	for(int i=1;i<=n-a;i++){
		ll ans1=c(b-1,b+i-2); 
		ll ans2=c(m-b-1,n-i+m-b-1);
		ans=(ans+ans1*ans2)%mod;
	}
	cout<<ans<<endl;
	return 0;
}