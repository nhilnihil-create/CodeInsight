#include<bits/stdc++.h>
#define Rep(i,a,b) for(register int i=(a);i<=(b);++i)
#define Repe(i,a,b) for(register int i=(a);i>=(b);--i)
#define pb push_back
#define Chkmax(a,b) a=a>b?a:b
#define Chkmin(a,b) a=a<b?a:b
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
    FILE*DSA=freopen("water.in","r",stdin);
    FILE*SDU=freopen("water.out","w",stdout);
#endif
}

const int MAXN=1e5+7;

static int n;

static int a[MAXN];

vector<int>ed[MAXN];

inline void init()
{
	read(n);
	Rep(i,2,n)read(a[i]),ed[a[i]].pb(i);
}

static int dp[MAXN];

vector<int>w[MAXN];

void dfs(int u)
{
	for(register int v:ed[u])dfs(v),w[u].pb(dp[v]);
	sort(w[u].begin(),w[u].end());
	if(!w[u].empty())Rep(i,0,w[u].size()-1)
		Chkmax(dp[u],w[u].size()-i+w[u][i]);
}

inline void solve()
{
	dfs(1);
	printf("%d\n",dp[1]);
}

int main()
{
    init();
    solve();
    return 0;
}
