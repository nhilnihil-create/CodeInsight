#include <iostream>
#include <cstdio>
#include <cstring>
#define N 100005
using namespace std;
struct edge{
	int k,next;
}e[N<<1];
int n,home[N],cnt=-1,f[N];
void add(int x,int y){
	cnt++;
	e[cnt].k=y;
	e[cnt].next=home[x];
	home[x]=cnt;
}
void dfs(int k,int F){
	for(int i=home[k];~i;i=e[i].next) if(e[i].k!=F){
		dfs(e[i].k,k);
		f[k]^=f[e[i].k]+1;
	}
}
int main(){
	memset(home,-1,sizeof(home));
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	dfs(1,0);
	if(f[1]) puts("Alice");
	else puts("Bob");
	return 0;
}