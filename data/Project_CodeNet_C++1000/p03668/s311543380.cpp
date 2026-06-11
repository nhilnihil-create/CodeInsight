#include<cstdio>
static const int M = (int)1e5+5;
struct node{
	int to;
	node *nxt;
	void add(int v){
		node *p=new node;
		p->to=v,p->nxt=nxt,nxt=p;
	}
}head[M];
int SG[M];
void dfs(int u,int f){
	SG[u]=0;
	for(node *i=head[u].nxt;i;i=i->nxt){
		int v=i->to;
		if(v==f)continue;
		dfs(v,u);
		SG[u]^=SG[v]+1;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1,u,v;i<n;++i){
		scanf("%d%d",&u,&v);
		head[u].add(v);
		head[v].add(u);
	}
	dfs(1,0);
	puts(SG[1]?"Alice":"Bob");
	return 0;
}