#include<cstdio>
const int N=400002;
int n,a,b,i,j,k;
int h[N],t[N],v[N],sg[N];
void add(int a,int b){
	t[++k]=h[a];
	h[a]=k;
	v[k]=b;
}
void init(){
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
}
void dfs(int i,int fa){
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa){
			dfs(v[j],i);
			sg[i]^=sg[v[j]]+1;
		}
}
int main(){
	init();
	dfs(1,0);
	printf("%s",sg[1]?"Alice":"Bob");
}