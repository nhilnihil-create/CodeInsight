#include<bits/stdc++.h>
#define M 100005
using namespace std;

struct edge{int u,next;}e[M*2]={0}; int head[M]={0},use=0;
void add(int x,int y){use++;e[use].u=y;e[use].next=head[x];head[x]=use;}
int dfs(int x,int fa){
	int res=0;
	for(int i=head[x];i;i=e[i].next) 
	if(e[i].u!=fa) res^=(1+dfs(e[i].u,x));
	return res;
}
int main(){
	int n; scanf("%d",&n);
	for(int i=1;i<n;i++){
		int x,y; scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	if(dfs(1,0)) printf("Alice\n");
	else printf("Bob\n");
}