#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<bitset>
#include<stack>
#include<cassert>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define mem(x,y) memset(x,y,sizeof x)
#define sqr(x) ((x)*(x))
//debug
#ifdef LOCAL
#define debug(...) fprintf(stderr,__VA_ARGS__)
#else
#define debug(...)
#endif
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
const int INF=2e9;
const db eps=1e-12;
template<typename T>
inline void read(T &x) {
  x=0; int f=1; char ch=getchar();
  while( (ch<'0' || ch>'9') && ch!='-') ch=getchar(); if(ch=='-') {f=-1; ch=getchar();}
  while(ch>='0' && ch <='9') x=x*10+ch-'0',ch=getchar();
  x*=f;
}
//==========================head template==========================
const int N=2010;
int n,K;
int head[N],nxt[N<<1],to[N<<1],lst=1;
inline void adde(int x,int y) {
  nxt[++lst]=head[x]; to[lst]=y; head[x]=lst;
}
bool vis[N];
int Dfs(int u,int dis) {
  int ret=0;
  vis[u]=1;
  for(int i=head[u];i;i=nxt[i])
    if(!vis[to[i]]) {
      int v=to[i];
      ret+=Dfs(v,dis+1);
    }
  return ret+(dis>K/2);
}
inline int Check(int u) {
  mem(vis,0);
  return Dfs(u,0);
}
inline int Work(int u,int v) {
  int ret=0;
  mem(vis,0); vis[v]=1;
  ret=Dfs(u,0);
  mem(vis,0); vis[u]=1;
  ret=ret+Dfs(v,0);
  return ret;
}
signed main() {
  read(n); read(K);
  for(int i=1;i<n;i++) {
    int x,y; read(x); read(y);
    adde(x,y); adde(y,x);
  }
  int ans=n+1;
  if(!(K&1))
    for(int i=1;i<=n;i++)
      ans=min(ans,Check(i));
  else
    for(int i=1;i<n;i++)
      ans=min(ans,Work(to[i<<1],to[i<<1|1]));
  printf("%d\n",ans);
  return 0;
}
