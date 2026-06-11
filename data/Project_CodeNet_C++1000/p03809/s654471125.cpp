#include<bits/stdc++.h>
#define Fst first
#define Snd second
#define RG register
#define mp make_pair
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long LL;
typedef long double LD;
typedef unsigned int UI;
typedef unsigned long long ULL;
template<typename T> inline void read(T& x) {
	char c = getchar();
	bool f = false;
	for (x = 0; !isdigit(c); c = getchar()) {
		if (c == '-') {
			f = true;
		}
	}
	for (; isdigit(c); c = getchar()) {
		x = x * 10 + c - '0';
	}
	if (f) {
		x = -x;
	}
}
template<typename T, typename... U> inline void read(T& x, U& ... y) {
	read(x), read(y...);
}
const int N=1e5+10;
int n,p;
int head[N],In[N];
LL F[N],G[N],sum[N],A[N];
bool YES[N];
struct Edge {
  int to,last;
  Edge () {}
  Edge (int a,int b) :to(a),last(b) {}
}edge[N<<1];
void ADD(int a,int b) {
  edge[++p]=Edge(b,head[a]); head[a]=p;
  edge[++p]=Edge(a,head[b]); head[b]=p;
}
void DFS(int u,int f) {
  if(In[u]==1) {
    F[u]=A[u];
    return;
  }
  int g=0; LL a=0,b=0;
  for(int i=head[u];i;i=edge[i].last) {
    int v=edge[i].to;
    if(v!=f) {
      ++g;
      DFS(v,u);
      sum[u]+=F[v];
      LL t=min(a,F[v]);
      a+=F[v]-t; b+=t;
    }
  }
  if(g==1) {
    YES[u]=true;
    if(sum[u]!=A[u]) puts("NO"),exit(0);
  }
  if(sum[u]>=A[u]&&sum[u]<=A[u]*2&&sum[u]-A[u]<=b) F[u]=A[u]*2-sum[u];
  else puts("NO"),exit(0);
}
void SFD(int u,int f) {
  if(In[u]==1) return;
  if((sum[u]+G[f])==A[u]*2ll) puts("YES"),exit(0);
  for(int i=head[u];i;i=edge[i].last) {
    int v=edge[i].to;
    if(v!=f) {
      if(YES[u]) {
        if(G[f]==A[u]) G[u]=G[f],SFD(v,u);
      }
      else {
        LL t=G[f]+sum[u]-F[v];
        if(t>=A[u]&&t<=A[u]*2) G[u]=A[u]*2-t,SFD(v,u);
      }
    }
  }
}
//#define rua
int main() {
//	ios::sync_with_stdio(false);
#ifdef rua
	freopen("GG.in","r",stdin);
#endif
  read(n);
  for(int i=1;i<=n;++i) read(A[i]);
  if(n==1) return puts("NO"),0;
  if(n==2) return puts(A[1]==A[2]?"YES":"NO"),0;
  for(int i=1;i<n;++i) {
    int u,v; read(u,v);
    ADD(u,v);
    ++In[u]; ++In[v];
  }
  int root=1;
  for(int i=1;i<=n;++i) if(In[i]!=1) root=i;
  DFS(root,0); SFD(root,0);
  puts("NO");
  return 0;
}
