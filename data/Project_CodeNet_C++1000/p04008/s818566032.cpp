#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#define FR first
#define SE second

using namespace std;

typedef pair<int,int> pr;

struct Edge {
  int t,next;
  Edge() {}
  Edge(int a,int b):t(a),next(b) {}
};

Edge e[100005];
int head[100005];

int dep[100005],fa[100005];

void dfs1(int x) {
  for(int i=head[x];i;i=e[i].next) {
  	int u=e[i].t;
  	dep[u]=dep[x]+1;
  	dfs1(u);
  }
}

bool vis[100005];

void dfs2(int x) {
  if (vis[x]) return;
  vis[x]=1;
  for(int i=head[x];i;i=e[i].next) dfs2(e[i].t);
}

pr a[100005];

int main() {
  int n,k;
  scanf("%d%d",&n,&k);
  int ans=0;
  for(int i=1;i<=n;i++) {
  	int x;
  	scanf("%d",&x);
  	if (i==1) {
  		if (x!=1) ans++;
	  }
	else {
		fa[i]=x;
		e[i]=Edge(i,head[x]);
		head[x]=i;
	}
  }
  dfs1(1);
  for(int i=2;i<=n;i++) a[i-1]=pr(dep[i],i);
  sort(a+1,a+n);
  for(int i=n-1;i>0;i--)
    if (!vis[a[i].SE]&&a[i].FR>k) {
    	ans++;
    	int p=a[i].SE;
    	for(int j=1;j<k;j++) p=fa[p];
    	dfs2(p);
	}
  printf("%d\n",ans);
  return 0;
}