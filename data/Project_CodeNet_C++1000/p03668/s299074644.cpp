#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Edge {
  int t,next;
  Edge() {}
  Edge(int a,int b):t(a),next(b) {}
};

Edge e[200005];
int head[100005];

int dfs(int x,int fa) {
  int s=0;
  for(int i=head[x];i;i=e[i].next)
    if (e[i].t!=fa) s^=dfs(e[i].t,x)+1;
  return s;
}

int main() {
  int n;
  scanf("%d",&n);
  for(int i=1;i<n;i++) {
  	int x,y;
  	scanf("%d%d",&x,&y);
  	e[2*i-1]=Edge(y,head[x]);
  	head[x]=2*i-1;
  	e[2*i]=Edge(x,head[y]);
  	head[y]=2*i;
  }
  puts((dfs(1,0))?"Alice":"Bob");
  return 0;
}