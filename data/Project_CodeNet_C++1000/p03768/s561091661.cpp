#include<cstdio>
const int N=200002;
int n,m,q,i,j,k,a,b,h[N],t[N],v[N];
int col[N],vis[N],x[N],d[N],c[N];
void add(int a,int b){
	t[++k]=h[a];
	h[a]=k;
	v[k]=b;
}
void init(){
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	scanf("%d",&q);
	for(i=1;i<=q;i++)
		scanf("%d%d%d",x+i,d+i,c+i);
}
void dfs(int i,int d,int c){
	if(vis[i]>>d)return;
	vis[i]|=1<<d;
	if(!col[i])col[i]=c;
	if(d)
		for(int j=h[i];j;j=t[j])
			dfs(v[j],d-1,c);
}
void work(){
	for(i=q;i;i--)
		dfs(x[i],d[i],c[i]);
	for(i=1;i<=n;i++)
		printf("%d\n",col[i]);
}
int main(){
	init();
	work();
	return 0;
}