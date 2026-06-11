#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N=100005;
const int inf=2000000000;

struct E{
	int to,next;
}mem[N<<1];
int n,x,y,num;
int head[N],dp[N];

void add(int x,int y){
	num++;
	mem[num].to=y; mem[num].next=head[x];
	head[x]=num;
}

void dfs(int k,int pre){
	int j,u;
	for (j=head[k];j;j=mem[j].next){
		u=mem[j].to;
		if (u==pre) continue;
		dfs(u,k);
		dp[k]^=dp[u]+1;
	}
}

int main(){
	int i;
	scanf("%d",&n);
	for (i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs(1,0);
	if (dp[1]) printf("Alice\n");
	else printf("Bob\n");
	return 0;
} 