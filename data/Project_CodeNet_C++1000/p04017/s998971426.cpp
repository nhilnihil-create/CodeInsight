#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define in read()
#define re register
#define fur(i,a,b) for(re int i=a;i<=b;++i)
#define fdr(i,a,b) for(re int i=a;i>=b;--i)
#define cl(a,b) memset(a,b,sizeof(a))
#define jinitaimei signed
#define int long long
inline int read()
{
	int x=0;
	char ch=getchar();
	for(;!isalnum(ch);ch=getchar());
	for(;isalnum(ch);ch=getchar()) x=x*10+ch-'0';
	return x;
}
const int xx=1e5+1612;
int to[xx][18];
int x[xx],n,L;
inline void init()
{
	n=in;
	fur(i,1,n) x[i]=in;
	L=in;
	int j=n;
	to[n][0]=j;
	fdr(i,n-1,1)
	{
		while(x[j]-x[i]>L) --j;
		to[i][0]=j;
	}
	fur(k,1,17) fur(i,1,n) to[i][k]=to[to[i][k-1]][k-1];
}
inline int power(int b,int k)
{
	int res=1;
	for(;k;k>>=1,b=b*b) if(k&1) res=res*b;
	return res;
}
inline void sol(int a,int b)
{
	if(a>b) swap(a,b);
	int j=a,g=17;
	int ans=0;
	while(j<b)
	{
		while(to[j][g]>b&&g) --g;
		if(b==n) while(to[j][g]==b&&g) --g;
		j=to[j][g];
		ans+=power(2,g);
	}
	printf("%lld\n",ans);
}
jinitaimei main()
{
	init();
	int T=in;
	while(T--) sol(in,in);
	return 0;
}
