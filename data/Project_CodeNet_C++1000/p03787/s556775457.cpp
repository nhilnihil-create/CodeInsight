#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;

const int N=200005;

struct E{
	int to,next;
}mem[N<<1];
int n,num,x,y,m,flag,s1,s2,s0,cnt;
ll ans;
int head[N],c[N];
bool vis[N];

void add(int x,int y){
	num++;
	mem[num].to=y; mem[num].next=head[x];
	head[x]=num;
}

void dfs(int k,int col){
	int j,u;
	vis[k]=1; c[k]=col; cnt++;
	for (j=head[k];j;j=mem[j].next){
		u=mem[j].to;
		if (vis[u]){
			if (c[u]!=(col^1)) flag=1;
			continue;
		}
		dfs(u,col^1);
	}
}

int main(){
	int i;
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	ans=0;
	for (i=1;i<=n;i++)
		if (!vis[i]){
			flag=0; cnt=0;
			dfs(i,0);
			if (cnt==1) s0++;
			else if (flag) s1++;
			else s2++;
		}
	ans=1ll*s0*s0+1ll*s1*s1+2ll*s2*s2;
	ans+=2ll*s0*(n-s0);
	if (s1) ans+=2ll*s1*s2;
	printf("%lld\n",ans);
	return 0;
}