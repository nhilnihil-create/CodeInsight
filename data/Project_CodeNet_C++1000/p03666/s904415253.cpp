#include<bits/stdc++.h>
#define Rep(i,a,b) for(register int i=(a);i<=(b);++i)
#define Repe(i,a,b) for(register int i=(a);i>=(b);--i)
#define rep(i,a,b) for(register int i=(a);i<(b);++i)
#define pb push_back
#define mx(a,b) (a>b?a:b)
#define mn(a,b) (a<b?a:b)
typedef unsigned long long uint64;
typedef unsigned int uint32;
typedef long long ll;
using namespace std;

namespace IO
{
	const uint32 Buffsize=1<<15,Output=1<<24;
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

	inline void readmd(int&x)
	{
		x=0;static char ch;
		for(ch=getc();!isdigit(ch);ch=getc());
		for(;isdigit(ch);ch=getc())x=(x*10ll+(ch^48))%998244353;
	}
}
using namespace IO;

void file()
{
	FILE*DSD=freopen("water.in","r",stdin);
	FILE*CSC=freopen("water.out","w",stdout);
}

const int MAXN=1e5+7;

static ll N,A,B,C,D;

inline void init()
{
	read(N),read(A),read(B),read(C),read(D);
}

inline void solve()
{
	A-=B,--N;
	Rep(i,0,N)if(A>=i*C-(N-i)*D&&A<=i*D-(N-i)*C)
		return(void)puts("YES");
	puts("NO");
}

int main()
{
	init();
	solve();
	return 0;
}