#include<bits/stdc++.h>
#define For(i,j,k) for(int i=j;i<=k;++i)
#define ll long long 
using namespace std;
const int N=1001000,INF=0x3f3f3f3f;
const int Mod=1e9+7;
template<class T>void read(T &x){
	x=0;char c=getchar();
	while(!isdigit(c))c=getchar();
	while( isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=getchar();
}
ll n,p[N],f[N],s[N];

int main(){
	read(n);
	f[1]=1;s[1]=1;
	For(i,2,n){
		f[i]=(f[i-1]+f[i])%Mod;
		if(i>3)f[i]=(f[i]+s[i-3])%Mod;
		s[i]=(s[i-1]+f[i])%Mod;
	}
	ll ans=f[n]*n%Mod;
	For(i,1,n-1){
		ll tmp=min(i+1ll,n-1);
		ans=(ans+f[i]*(n-1)%Mod*(n-1)%Mod)%Mod;
		ans=(ans+f[i]*tmp%Mod)%Mod;
	}
	printf("%lld\n",ans);
	return 0;
}
