#include<bits/stdc++.h>
#define M 100005
using namespace std;

struct edge{int u,next;}e[M]={0}; int head[M]={0},use=0;
void add(int x,int y){use++;e[use].u=y;e[use].next=head[x];head[x]=use;}
int n,k,cnt=0,a[M]={0};

int dfs(int x,int dep){
	int maxn=dep;
	for(int i=head[x];i;i=e[i].next) maxn=max(maxn,dfs(e[i].u,dep+1));
	if(a[x]!=1&&maxn-dep==k-1) {cnt++; return 0 ;} else return maxn;
}	

int main(){
	scanf("%d%d",&n,&k); 
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		if(i!=1) add(a[i],i);
		else cnt+=(a[i]!=1);
	} 
	for(int i=head[1];i;i=e[i].next)
	dfs(e[i].u,0);
	cout<<cnt<<endl;
}