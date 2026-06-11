#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=200005,Mod=1e9+7;
int fac[N],inv[N];
inline int qpow(int a,int b){
	int ans=1;
	while (b){
		if (b&1) ans=1ll*ans*a%Mod;
		a=1ll*a*a%Mod,b>>=1;
	}
	return ans;
}
inline void init(){
	fac[0]=1;for (int i=1;i<=200000;i++) fac[i]=1ll*fac[i-1]*i%Mod;
	inv[200000]=qpow(fac[200000],Mod-2);
	for (int i=199999;i>=0;i--) inv[i]=1ll*inv[i+1]*(i+1)%Mod;
}
inline int C(int n,int m){
	return 1ll*fac[n]*inv[m]%Mod*inv[n-m]%Mod;
}
inline int calc(int x1,int y1,int x2,int y2){
	return C(x2-x1+y2-y1,x2-x1);
}
int main (){
	int n,m,a,b;scanf ("%d%d%d%d",&n,&m,&a,&b);
	init();
	int ans=0,lst=0;
	for (int i=1;i<=n-a;i++){
		ans=(ans+1ll*(calc(1,1,i,b+1)-lst+Mod)%Mod*calc(i,b+1,n,m)%Mod)%Mod;
		lst=calc(1,1,i,b+1);
	}
	printf ("%d",ans);
	return 0;
}
