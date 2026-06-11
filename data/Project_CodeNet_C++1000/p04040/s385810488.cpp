#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define re register
#define ll long long
inline int gi(){
	int f=1,sum=0;char ch=getchar();
	while(ch>'9' || ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){sum=(sum<<3)+(sum<<1)+ch-'0';ch=getchar();}
	return f*sum;
}
const int Mod=1e9+7,N=200010;
int fac[N],inv[N],n,m,a,b;
int qpow(int a,int b){int ret=1;while(b){if(b&1)ret=1ll*ret*a%Mod;b>>=1;a=1ll*a*a%Mod;}return ret;}
int C(int p,int q){if(p<q || p<0 || q<0)return 0;return 1ll*fac[p]*inv[q]%Mod*inv[p-q]%Mod;}
int main(){
	n=gi();m=gi();
	a=gi();b=gi();int ans=0;fac[0]=inv[0]=inv[1]=1;
	for(int i=1;i<=200000;i++)fac[i]=1ll*fac[i-1]*i%Mod;
	for(int i=2;i<=200000;i++)inv[i]=1ll*(Mod-Mod/i)*inv[Mod%i]%Mod;
	for(int i=2;i<=200000;i++)inv[i]=1ll*inv[i-1]*inv[i]%Mod;
	for(int i=1;i<=n-a;i++)
		ans=(ans+1ll*C(b+i-2,i-1)*C(n-i+m-b-1,n-i)%Mod)%Mod;
	printf("%d\n",ans);
	return 0;
}