#include<bits/stdc++.h>
using namespace std;
#define N 200011
typedef struct{
	int to,nxt;
}edge;
edge e[N<<2];
int head[N<<2],sg[N],n,a,b,cnt;
void add(int a,int b){
	cnt++;
	e[cnt].to=b;
	e[cnt].nxt=head[a];
	head[a]=cnt;
}
void dfs(int u,int fa){
	sg[u]=0;
	for(int i=head[u];i!=-1;i=e[i].nxt){
		int v=e[i].to;
		if(v==fa) continue;
		dfs(v,u);
		sg[u]^=(sg[v]+1);
	}
}
int main(){
	memset(head,-1,sizeof(head));
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		scanf("%d%d",&a,&b);
		add(a,b);add(b,a);
	}
	dfs(1,0);
	if(sg[1]==0) printf("Bob\n");else printf("Alice\n");
}