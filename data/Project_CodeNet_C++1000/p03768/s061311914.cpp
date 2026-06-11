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
int n,m,p,Q;
int head[N],col[N],V[N],D[N],C[N];
bool vis[N][11];
struct Edge {
  int to,last;
  Edge () {}
  Edge (int a,int b) :to(a),last(b) {}
}edge[N<<1];
void ADD(int a,int b) {
  edge[++p]=Edge(b,head[a]); head[a]=p;
  edge[++p]=Edge(a,head[b]); head[b]=p;
}
void DFS(int u,int d,int c) {
  if(!col[u]) col[u]=c;
  if(vis[u][d]||!d) return;
  int t=d;
  while(t&&!vis[u][t]) vis[u][t--]=true;
  for(int i=head[u];i;i=edge[i].last) {
    int v=edge[i].to;
    DFS(v,d-1,c);
  }
}
//#define rua
int main() {
//	ios::sync_with_stdio(false);
#ifdef rua
	freopen("GG.in","r",stdin);
#endif
  read(n,m);
  for(int i=1;i<=m;++i) {
    int u,v; read(u,v);
    ADD(u,v);
  }
  read(Q);
  for(int i=1;i<=Q;++i) read(V[i],D[i],C[i]);
  for(int i=Q;~i;--i) DFS(V[i],D[i],C[i]);
  for(int i=1;i<=n;++i) printf("%d\n",col[i]);
  return 0;
}
