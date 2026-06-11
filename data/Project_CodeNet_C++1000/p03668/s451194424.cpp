//%std
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define lovelive long long
#define lc son[x][0]
#define rc son[x][1]
#define lowbit(x) (x&(-x))
#define pt vc
const int N=1e5+100; 
void read(int &x)
{
  int p=1;
  x=0;
  char c=getchar();
  while(c<'0'||c>'9')
  {
    if(c=='-')
      p=-1;
    c=getchar();
  }
  while(c>='0'&&c<='9')
  {
  	x=x*10+c-48;
  	c=getchar();
  }
  x*=p;
}
int fir[N],nxt[N<<1],to[N<<1],tot;
void add_edge(int x,int y)
{
  nxt[++tot]=fir[x];
  fir[x]=tot;
  to[tot]=y;
} 
int sg[N];
void dfs(int i,int f)
{
  for(int j=fir[i];j;j=nxt[j])
    if(to[j]!=f)
      dfs(to[j],i),sg[i]^=(sg[to[j]]+1);  
} 
int main()
{
  int n,x,y;
  read(n);
  for(int i=1;i<n;i++)
  {
    read(x);read(y);
    add_edge(x,y);
    add_edge(y,x);
  }
  dfs(1,0);
  if(sg[1])
    puts("Alice");
  else
    puts("Bob");
  return 0;
}
