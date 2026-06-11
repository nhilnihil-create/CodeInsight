
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
 
Edge e[200005];
int head[100005],d[100005];
 
ll num[100005];
 
ll dfs(int x,int fa) {
  if (d[x]==1) return num[x];
  ll sum=0,maxn=0;
  for(int i=head[x];i;i=e[i].next)
    if (e[i].t!=fa) {
        int u=e[i].t;
        ll s=dfs(u,x);
        if (s<0) return -1;
        sum+=s;maxn=max(maxn,s);
    }
  ll t=(maxn>sum-maxn)?sum-maxn:(sum>>1);
  return (sum>=num[x]&&sum-num[x]<=t)?(num[x]<<1)-sum:-1;
}
 
int main() {
  int n;
  scanf("%d",&n);
  for(int i=1;i<=n;i++) scanf("%lld",&num[i]);
  for(int i=1;i<n;i++) {
    int x,y;
    scanf("%d%d",&x,&y);
    e[2*i-1]=Edge(y,head[x]);
    head[x]=2*i-1;
    e[2*i]=Edge(x,head[y]);
    head[y]=2*i;
    d[x]++;d[y]++;
  }
  if (n==2) {
    puts((num[1]==num[2])?"YES":"NO");
    return 0;
  }
  int rt=0;
  for(int i=1;i<=n;i++)
    if (d[i]>1) rt=i;
  puts((dfs(rt,0)==0)?"YES":"NO");
  return 0;
}
