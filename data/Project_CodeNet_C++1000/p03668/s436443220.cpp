#include<cstdio>
const int N=1e5+5,M=2*N;
int n,i,et,he[N],sg[N];
struct edge{int l,to;}e[M];
int read(){
	char c=getchar();int k=0;for (;c<48||c>57;c=getchar());
	for (;c>47&&c<58;c=getchar()) k=(k<<3)+(k<<1)+c-48;return k;
}
void dfs(int x,int fa){
	for (int i=he[x];i;i=e[i].l) if (e[i].to!=fa)
		dfs(e[i].to,x),sg[x]^=sg[e[i].to]+1;
}
int main(){
	for (n=read(),i=1;i<n;i++){
		int x=read(),y=read();
		e[++et].l=he[x];he[x]=et;e[et].to=y;
		e[++et].l=he[y];he[y]=et;e[et].to=x;
	}
	dfs(1,0);
	puts(sg[1]?"Alice":"Bob");
}