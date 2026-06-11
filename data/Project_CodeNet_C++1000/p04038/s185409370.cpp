#include<bits/stdc++.h>
#define Rep(i,a,b) for(register int i=(a);i<=(b);++i)
#define Repe(i,a,b) for(register int i=(a);i>=(b);--i)
#define pb push_back
#define Chkmax(a,b) a=a>b?a:b
#define Chkmin(a,b) a=a<b?a:b
#define mx(a,b) (a>b?a:b)
#define mn(a,b) (a<b?a:b)
typedef unsigned long long uint64;
typedef unsigned int uint32;
typedef long long ll;
using namespace std;

namespace IO
{
    const uint32 Buffsize=1<<15,Output=1<<23;
    static char Ch[Buffsize],*S=Ch,*T=Ch;
    inline char getc()
	{
		return((S==T)&&(T=(S=Ch)+fread(Ch,1,Buffsize,stdin),S==T)?0:*S++);
	}
    static char Out[Output],*nowps=Out;
    
    inline void flush(){fwrite(Out,1,nowps-Out,stdout);nowps=Out;}

    template<typename T>inline void read(T&x)
	{
		x=0;static char ch;T f=1;
		for(ch=getc();!isdigit(ch);ch=getc())if(ch=='-')f=-1;
		for(;isdigit(ch);ch=getc())x=x*10+(ch^48);
		x*=f;
	}

	template<typename T>inline void write(T x,char ch='\n')
	{
		if(!x)*nowps++='0';
		if(x<0)*nowps++='-',x=-x;
		static uint32 sta[111],tp;
		for(tp=0;x;x/=10)sta[++tp]=x%10;
		for(;tp;*nowps++=sta[tp--]^48);
		*nowps++=ch;
	}
}
using namespace IO;

inline void file()
{
#ifndef ONLINE_JUDGE
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
#endif
}

const int MAXN=2011;

static int n,k,dp[MAXN][MAXN];

inline void init()
{
	read(n);read(k);
}

const int mod=1e9+7;

inline int ad(int u,int v){return(u+=v)>=mod?u-mod:u;}

static int func[MAXN*MAXN],inv[MAXN*MAXN];

inline int power(int u,int v)
{
	static int sm;
	for(sm=1;v;v>>=1,u=(uint64)u*u%mod)if(v&1)
		sm=(uint64)sm*u%mod;
	return sm;
}

inline int C(int u,int v)
{return u>=v?(uint64)func[u]*inv[v]%mod*inv[u-v]%mod:0;}

inline void solve()
{
	if(k==1)return (void)printf("1\n");

	dp[0][0]=1;
	
	func[0]=1;
	Rep(i,1,n*k)func[i]=(uint64)func[i-1]*i%mod;
	inv[n*k]=power(func[n*k],mod-2);
	Repe(i,n*k,1)inv[i-1]=(uint64)inv[i]*i%mod;

	Rep(i,0,n)Rep(j,i,n)
	{
		if(j>i)dp[i][j]=dp[i][j-1];
		if(i)dp[i][j]=ad(dp[i][j],(uint64)dp[i-1][j]*
			C(n*k-(i-1)*(k-1)-j-1,k-2)%mod);
	}
	printf("%d\n",(uint64)dp[n][n]*func[n]%mod);
}

int main()
{
    init();
    solve();
    return 0;
}
