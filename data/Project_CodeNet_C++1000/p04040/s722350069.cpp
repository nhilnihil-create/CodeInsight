#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
const int maxn=1e5;
int n,m,a,b,ans;
int fac[maxn*2+8],fact[maxn*2+8];

int read()
{
    int x=0,f=1;char ch=getchar();
    for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
    for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
    return x*f;
}

int C(int n,int m){return 1ll*fac[n]*fact[m]%mod*fact[n-m]%mod;}
int power(int a,int k)
{
    int sum=1;
    for (;k;k>>=1,a=1ll*a*a%mod)
	if (k&1)
	    sum=1ll*sum*a%mod;
    return sum;
}

int main()
{
    n=read(),m=read(),a=read(),b=read();
    fact[0]=fac[0]=1;
    for (int i=1;i<=n+m;i++) fac[i]=1ll*fac[i-1]*i%mod;
    fact[n+m]=power(fac[n+m],mod-2);
    for (int i=n+m-1;i;i--) fact[i]=1ll*fact[i+1]*(i+1)%mod;
    for (int i=1;i<=n-a;i++) ans=(ans+1ll*C(i-1+b-1,i-1)*C(n+m-i-b-1,n-i)%mod)%mod;
    printf("%d\n",ans);
    return 0;
}
