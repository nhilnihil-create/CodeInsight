#include<cstdio>
#include<fstream>
#include<queue>
#include<iostream>
#include<cstring>
#define N 100010
using namespace std;
int n,m;
struct rode{
  int y,next;
}e[N<<1]={};
int fl[N]={},len=0;
int a[N]={};
inline int read()
{
	int s = 0, w = 1;
	char c = getchar();
	while ((c<'0' || c>'9') && c != '0')c = getchar();
	if (c == '-')w = -1, c = getchar();
	while (c <= '9'&&c >= '0')s = (s << 3) + (s << 1) + c - '0', c = getchar();
	return s * w;
}
inline void inc(int x,int y)
{
  e[++len].y=y;
  e[len].next=fl[x];
  fl[x]=len;
}
struct que{
  int u,d,c;
}qu[N]={};
int c[N]={};
bool vis[N]={};
int s=0;
void dfs(int u,int v,int d,int co)
{
  if(d==0)return ;
  for(int i=fl[u];i;i=e[i].next)
   {
     int vv=e[i].y;
     if(vis[vv])continue;
     if(c[vv]==0)c[vv]=co,--s;
     if(s==0)return ;
     vis[vv]=1;
     dfs(vv,v,d-1,co);
     vis[vv]=0;
   }
}
int main()
{
  n=read();m=read();
  s=n;
  // for(int i=1;i<=n;++i)a[i]=read(),c[i]=0;
  for(int i=1;i<=m;++i)
  {
    int x=read(),y=read();
    inc(x,y);inc(y,x);
  }
  int q=read();
  for(int i=1;i<=q;++i)qu[i].u=read(),qu[i].d=read(),qu[i].c=read();
  for(int i=q;i>=1;--i)
  {
    int u=qu[i].u,d=qu[i].d,co=qu[i].c;
    if(c[u]==0)c[u]=co,--s;
    if(s==0)break;
    vis[u]=1;
    dfs(u,u,d,co);
    vis[u]=0;
  }
  for(int i=1;i<=n;++i)printf("%d\n",c[i]);
  return 0;
}
