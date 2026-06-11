#include<cstdio>
const int N=400020;
int n,h[N],t[N],v[N],a,b,i,k;
int g[N];
void add(int a,int b){
	t[++k]=h[a];
	h[a]=k;
	v[k]=b;
}
void dfs(int i,int fa){
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa){
			dfs(v[j],i);
			g[i]^=g[v[j]]+1;
		}
}
int main(){
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	dfs(1,0);
	printf("%s",g[1]?"Alice":"Bob");
}
