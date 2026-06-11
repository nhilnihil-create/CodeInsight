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
int n,m,p;
int head[N];
bool vis[N];
vector<int> G[2];
struct Edge {
  int to,last;
  Edge () {}
  Edge (int a,int b) :to(a),last(b) {}
}edge[N<<1];
void ADD(int a,int b) {
  edge[++p]=Edge(b,head[a]); head[a]=p;
  edge[++p]=Edge(a,head[b]); head[b]=p;
}
void DFS(int u,int id) {
  vis[u]=true;
  if(u!=1||id) G[id].push_back(u);
  for(int& i=head[u];i;i=edge[i].last) {
    int v=edge[i].to;
    if(!vis[v]) {
      DFS(v,id);
      break;
    }
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
  DFS(1,0); DFS(1,1);
  printf("%d\n",G[0].size()+G[1].size());
  reverse(G[0].begin(),G[0].end());
  for(auto v: G[0]) printf("%d ",v);
  for(auto v: G[1]) printf("%d ",v);
  return 0;
}
