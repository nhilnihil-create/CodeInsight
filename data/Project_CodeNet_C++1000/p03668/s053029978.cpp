#include<iostream>
#include<cstdio>
#define N 200009
using namespace std;
double ans;
int head[N],tot,sg[N],n;
inline int rd(){
	int x=0;char c=getchar();bool f=0;
	while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f?-x:x;
}
struct edge{int n,to;}e[N<<1];
inline void add(int u,int v){e[++tot].n=head[u];e[tot].to=v;head[u]=tot;}
void dfs(int u,int fa){
	for(int i=head[u];i;i=e[i].n)if(e[i].to!=fa){
		int v=e[i].to;dfs(v,u);
		sg[u]^=(sg[v]+1);
	}
}
int main(){
    n=rd();int u,v;
	for(int i=1;i<n;++i){
		u=rd();v=rd();
		add(u,v);add(v,u);
	}
	dfs(1,0);
	if(sg[1])puts("Alice");
	else puts("Bob");
	return 0;
} 