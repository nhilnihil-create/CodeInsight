#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#define inf 2147483647
#define eps 1e-9
using namespace std;
typedef long long ll;
struct edge{
	int v,next;
}a[200001];
int n,u,v,tot=0,head[100001];
void add(int u,int v){
	a[++tot].v=v;
	a[tot].next=head[u];
	head[u]=tot;
}
int dfs(int u,int fa){
	int ret=0;
	for(int tmp=head[u];tmp!=-1;tmp=a[tmp].next){
		int v=a[tmp].v;
		if(v!=fa){
			ret^=(dfs(v,u)+1);
		}
	}
	return ret;
}
int main(){
	memset(head,-1,sizeof(head));
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	if(dfs(1,-1))puts("Alice");
	else puts("Bob");
	return 0;
}