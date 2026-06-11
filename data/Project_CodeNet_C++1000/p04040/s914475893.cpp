#include<bits/stdc++.h>
#define N 200010
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;
	static int p;p=1;
	static char c;c=getchar();
	while(!isdigit(c)){if(c=='-')p=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c-'0');c=getchar();}
	x*=p;
}
const int mod=1e9+7;
int n,m,a,b;
int fac[N],inv[N];
long long ksm(long long x,long long mc)
{
	long long tmp=x%mod;
	long long res=1;
	while(mc)
	{
		if(mc&1)res=res*tmp%mod;
		tmp=tmp*tmp%mod;
		mc>>=1;
	}
	return res;
}
void init(int maxn)
{
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	for(int i=2;i<=maxn;i++) fac[i]=(long long)fac[i-1]*i%mod;
	inv[maxn]=ksm(fac[maxn],mod-2);
	for(int i=maxn-1;i>=2;i--) inv[i]=(long long)inv[i+1]*(i+1)%mod;
}
long long C(int i,int j)
{
	if(i<j)return 0;
	return (long long)fac[i]*inv[j]%mod*inv[i-j]%mod;
}
int main()
{
//	freopen("ARC058D.in","r",stdin);
//	freopen("ARC058D.out","w",stdout);
	read(n);read(m);read(a);read(b);
	init(n+m);
	int ans=0;
	for(int i=1;i<=n-a;i++)
		(ans+=C(i+b-2,b-1)*C(n-i+m-b-1,n-i)%mod)%=mod;
	printf("%d\n",ans);
	return 0;
}