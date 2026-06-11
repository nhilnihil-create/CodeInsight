#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define ll long long
#define inf 0x3f3f3f3f
#define maxn 100010
inline ll read()
{
	ll x=0; char c=getchar(),f=1;
	for(;c<'0'||'9'<c;c=getchar())if(c=='-')f=-1;
	for(;'0'<=c&&c<='9';c=getchar())x=x*10+c-'0';
	return x*f;
}
inline void write(ll x)
{
	static char buf[20];
	int len=0;
	if(x<0)putchar('-'),x=-x;
	for(;x;x/=10)buf[len++]=x%10+'0';
	if(!len)putchar('0');
	else while(len)putchar(buf[--len]);
}
inline void writesp(ll x){write(x); putchar(' ');}
inline void writeln(ll x){write(x); putchar('\n');}
int x[maxn],y[maxn];
struct edge{
	int to,nxt;
}e[2*maxn];
int fir[maxn];
int n,m,tot;
inline void add_edge(int x,int y){e[tot].to=y; e[tot].nxt=fir[x]; fir[x]=tot++;}
int dfs(int now,int fa,int dep)
{
	int cur=(dep>m/2);
	for(int i=fir[now];~i;i=e[i].nxt)
		if(e[i].to!=fa)cur+=dfs(e[i].to,now,dep+1);
	return cur;
}
int main()
{
	n=read(); m=read();
	memset(fir,255,sizeof(fir)); tot=0;
	for(int i=1;i<n;i++){
		x[i]=read(); y[i]=read();
		add_edge(x[i],y[i]); add_edge(y[i],x[i]);
	}
	int ans=inf;
	if(m&1){
		for(int i=1;i<n;i++)
			ans=std::min(ans,dfs(x[i],y[i],0)+dfs(y[i],x[i],0));
	}
	else{
		for(int i=1;i<=n;i++)
			ans=std::min(ans,dfs(i,-1,0));
	}
	writeln(ans);
	return 0;
}