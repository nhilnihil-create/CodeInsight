#include <bits/stdc++.h>
using namespace std;

#define MAXN 400010

class IO{char buffer[3000001];char *h;int len;inline char gchar(){return *h++;}inline bool validdigit(char c){return c>='0' && c<='9';}public:inline void init(){len=fread(buffer,1,3000000,stdin);h=buffer;}inline int nextint(){register int i=0;register char c;do c=gchar();while(!validdigit(c));do{i=i*10+c-48;c=gchar();}while(validdigit(c));return i;}inline int nextsigned(){register int i=0,f=1;register char c;do{c=gchar();if(c=='-')f=-1;}while(!validdigit(c));do{i=i*10+c-48;c=gchar();}while(validdigit(c));return i*f;}inline long long nextlonglong(){register long long i=0;register char c;do c=gchar();while(!validdigit(c));do{i=i*10+c-48;c=gchar();}while(validdigit(c));return i;}inline long long nextsignedlonglong(){register long long i=0,f=1;register char c;do{c=gchar();if(c=='-')f=-1;}while(!validdigit(c));do{i=i*10+c-48;c=gchar();}while(validdigit(c));return i*f;}inline char nextchar(){register char c;do c=gchar();while(c<=' ');return c;}}io;

int head[MAXN],to[MAXN],nxt[MAXN];
int no,c2,el,n,m,cnt;
char color[MAXN];
bool visit[MAXN];

void cover(int u)
{
	visit[u]=true;
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(visit[v])continue;
		cover(v);
	}
}

bool dfs(int u)
{
	bool check=visit[u]=true;
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(color[v]==color[u]){check=false;break;}
		if(color[v])continue;
		color[v]=color[u]^3;
		if(!dfs(v)){check=false;break;}
	}
	cover(u);
	return check;
}

int main()
{
	io.init();
	n=io.nextint();
	m=io.nextint();
	for(int i=1;i<=m;++i)
	{
		int u=io.nextint(),v=io.nextint();
		nxt[++cnt]=head[u];
		to[cnt]=v;
		head[u]=cnt;
		nxt[++cnt]=head[v];
		to[cnt]=u;
		head[v]=cnt;
	}
	for(int i=1;i<=n;++i)
	{
		if(visit[i])continue;
		if(!head[i])++no;
		else
		{
			color[i]=1;
			if(dfs(i))++c2;else ++el;
		}
	}
	printf("%lld\n",(long long)no*no+(long long)no*(n-no)*2+(long long)el*c2*2+(long long)el*el+(long long)c2*c2*2);
}