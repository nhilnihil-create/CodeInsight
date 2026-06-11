#include<bits/stdc++.h>
#define mod 1000000007
#define maxn 200000
using namespace std;
int h,w,a,b,ans;
int fac[200005],ifac[200005];

int ksm(int x,int y){
	int res=1;
	while(y){
		if(y&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod,y/=2;
	}
	return res;
}

int C(int x,int y){
	int res=1ll*fac[x]*ifac[y]%mod*ifac[x-y]%mod;
	return res;
}

int main(){
	scanf("%d %d %d %d",&h,&w,&a,&b);
	fac[0]=1;for(int i=1;i<=maxn;i++) fac[i]=1ll*i*fac[i-1]%mod;
	ifac[maxn]=ksm(fac[maxn],mod-2);
	for(int i=maxn-1;i>=0;i--) ifac[i]=1ll*(i+1)*ifac[i+1]%mod;
	for(int i=1;i<=h-a;i++){
		ans+=1ll*C(i-1+b-1,i-1)*C(h-i+w-b-1,h-i)%mod;
		if(ans>=mod) ans-=mod;
	}
	printf("%d\n",ans);

	return 0;
}