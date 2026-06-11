#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#define int long long
using namespace std;
inline int read(){
	int x=0,w=0;char c=getchar();
	while(!isdigit(c))w|=c=='-',c=getchar();
	while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return w?-x:x;
}
namespace star{
	const int maxn=1e5,mod=1e9+7;
	int h,w,a,b;
	inline int fpow(int a,int b){
		int ans=1;
		for(;b;b>>=1,a=a*a%mod)if(b&1)ans=ans*a%mod;
		return ans;
	}
	int mul[maxn*2+10],inv[maxn*2+10];
	inline void pre(int n){
		mul[0]=inv[0]=1;
		for(int i=1;i<=n;i++)
			mul[i]=mul[i-1]*i%mod;
		inv[n]=fpow(mul[n],mod-2);
		for(int i=n-1;i;i--)
			inv[i]=inv[i+1]*(i+1)%mod;
	}	
	inline int C(int n,int m){
		return mul[n]*inv[n-m]%mod*inv[m]%mod;
	}
	inline void work(){
		h=read(),w=read(),a=read(),b=read();
		pre(h+w);
		int ans=0;
		for(int i=b+1;i<=w;i++)
			ans=(ans+C(h-a+i-2,i-1)*C(w+a-i-1,a-1)%mod)%mod;
		printf("%lld\n",ans);
	}
}
signed main(){
	star::work();
	return 0;
}