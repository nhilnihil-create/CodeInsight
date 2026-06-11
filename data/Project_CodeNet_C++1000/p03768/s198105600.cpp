#include<bits/stdc++.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
const int big=0x7fffffff;
using namespace std;
inline void read(int &x)
{
    x=0;char ch=getchar();int pd=1;
    while(ch<'0'||ch>'9'){if(ch=='-')pd=-pd;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    x*=pd;
}
inline void write(const int &x)
{
    char ggg[10001];int s=0;int tmp=x;
    if(tmp==0){putchar('0');return;}
    if(tmp<0){tmp=-tmp;putchar('-');}
    while(tmp>0){ggg[s++]=tmp%10+'0';tmp/=10;}
    while(s>0){putchar(ggg[--s]);}
}
const int N=1e5+233;
int mx[N],vis[N],t,h[N];

struct dd
{
	int end,nt;
}e[N<<1];

inline void add(int begin,int end)
{
	++t;
	e[t].end=end;
	e[t].nt=h[begin];
	h[begin]=t;
}

void dfs(int x,int d,int s)
{
	if(mx[x]>=d)return;
	if(!vis[x])vis[x]=s;
	mx[x]=max(mx[x],d);
	if(!d)return;
	for(register int i=h[x];i;i=e[i].nt)
	{
		int u=e[i].end;
		dfs(u,d-1,s);
	}
}
const int Q=1e5+233;
int n,m,q,xx[N],d[N],c[N];



int main()
{
	memset(mx,-1,sizeof(mx));
	read(n);
	read(m);
	for(register int i=1;i<=m;++i)
	{
		int xx,yy;
		read(xx);
		read(yy);
		add(xx,yy);
		add(yy,xx);
	}
	read(q);
	for(register int i=1;i<=q;++i)
	{
		read(xx[i]);
		read(d[i]);
		read(c[i]);
	}
	for(register int i=q;i>=1;--i)
	{
		dfs(xx[i],d[i],c[i]);
	}
	for(register int i=1;i<=n;++i)
	{
		write(vis[i]);
		putchar('\n');
	}
	return 0;
}