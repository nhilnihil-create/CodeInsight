#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Edge {
  int t,next;
  Edge() {}
  Edge(int a,int b):t(a),next(b) {}
};

Edge e[400005];
int head[200005];

bool vis[100005],col[100005];
int cnt;
bool can;

void dfs(int x,int c) {
  vis[x]=1;cnt++;
  col[x]=c;
  for(int i=head[x];i;i=e[i].next)
    if (!vis[e[i].t]) dfs(e[i].t,c^1);
    else if (!(col[x]^col[e[i].t])) can=0;
}

int main() {
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i=1;i<=m;i++) {
  	int x,y;
  	scanf("%d%d",&x,&y);
  	e[2*i-1]=Edge(y,head[x]);
  	head[x]=2*i-1;
  	e[2*i]=Edge(x,head[y]);
  	head[y]=2*i;
  }
  int s1=0,s2=0,s3=0;
  for(int i=1;i<=n;i++)
    if (!vis[i]) {
    	cnt=0;can=1;
    	dfs(i,0);
    	if (cnt==1) s3++;
    	else if (can) s1++;
    	else s2++;
	}
  ll ans=(ll)n*n-(ll)(n-s3)*(n-s3);
  ans+=(ll)(s1+s2)*(s1+s2)+(ll)s1*s1;
  printf("%lld\n",ans);
  return 0;
}