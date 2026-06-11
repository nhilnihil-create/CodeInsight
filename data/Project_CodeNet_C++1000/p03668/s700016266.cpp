#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int n,tot=0,head[100001];
struct data {
    int next,num;
}edge[200001];
void add(int u,int v) {
    edge[++tot].next=head[u];
    edge[tot].num=v;
    head[u]=tot;
}
int dfs(int x,int fa) {
    int ans=0;
    for (int i=head[x];i!=-1;i=edge[i].next) {
	int kx=edge[i].num;
	if (kx==fa) continue;
	ans^=dfs(kx,x)+1;
    }
    return ans;
}
int main() {
    memset(head,-1,sizeof(head));
    scanf("%d",&n);
    for (int i=1;i<n;i++) {
	int u,v;
	scanf("%d%d",&u,&v);
	add(u,v);
	add(v,u);
    }
    int ans=dfs(1,-1);
    if (ans) printf("Alice\n");
    else printf("Bob\n");
    return 0;
}
