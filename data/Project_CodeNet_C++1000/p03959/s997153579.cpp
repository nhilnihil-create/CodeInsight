#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#define RG register
#define LL long long
using namespace std;
const int N=1e5+10;
const LL mod=1e9+7;
int n,fi[N];
LL ans=1,t[N],a[N],ri[N],maxx;
template<typename I> inline void read(I &ot){
	I ch=getchar(), x=0, f=1;
	while(ch<'0' || ch>'9'){if(ch=='-') f=-1; ch=getchar();	}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0'; ch=getchar();	}
	ot=x*f;}
template<typename I, typename... U> inline void read(I &x,U&... y){read(x); read(y...);}
template<typename I>inline I mi(const I&a,const I&b){return a<b ? a : b;}
inline void endd(){printf("0\n"); exit(0);}
int main()
{
//	freopen("Two Alpinists.in","r",stdin);
	read(n);
	for(RG int i=1;i<=n;i++)
	{
		read(t[i]);
		if(t[i]!=t[i-1]) ri[i]=t[i], fi[i]=1, maxx=t[i];
		else ri[i]=maxx;
	}
	for(RG int i=1;i<=n;i++) read(a[i]);
	for(RG int i=n;i;i--)
	 if(a[i]!=a[i+1])
	 {
		if(fi[i] && a[i]!=t[i]) endd();
		if(a[i]>ri[i]) endd();
		ri[i]=a[i]; fi[i]=1; maxx=a[i];
	 }
	 else ri[i]=mi(ri[i],maxx);
	for(RG int i=1;i<=n;i++)
	{
		if(fi[i]) continue ;
		(ans*=ri[i])%=mod;
	}
	printf("%lld\n",ans);
	return 0;
}