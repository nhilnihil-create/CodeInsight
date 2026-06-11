#include<bits/stdc++.h>
#define re register
#define inc(i,j,k) for(re int i=j;i<=k;i++)
#define edge(u) for(re int i=head[u];i;i=e[i].nxt)
using namespace std;
const int N=1e5+5;
inline int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while('0'<=ch&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x;
}
int n,head[N],sg[N],cnt;
struct edge{
	int to,nxt;
}e[N<<1];
void add(int a,int b){
	e[++cnt].to=b;
	e[cnt].nxt=head[a];
	head[a]=cnt;
}
void dfs(int u,int f){
	edge(u){
		int v=e[i].to;
		if(v==f) continue;
		dfs(v,u);
		sg[u]^=(sg[v]+1);
	}
}
int main(){
	n=read();
	inc(i,2,n){
		int a=read(),b=read();
		add(a,b),add(b,a);
	}
	dfs(1,0);
	if(sg[1]) puts("Alice");
	else puts("Bob");
}