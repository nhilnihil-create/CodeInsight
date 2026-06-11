#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;

#define LL long long
#define DB double
#define MAXN 1000000
#define MOD 998244353
#define Pr pair<int,int>
#define X first
#define Y second
#define INF 1000000000000000000
#define mem(x,v) memset(x,v,sizeof(x))

LL read(){
	LL x=0,F=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')F=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*F;
}

int n,rt,du[MAXN+5];LL d[MAXN+5],a[MAXN+5];
vector<int> G[MAXN+5];

void dfs(int x,int fa){
	if(du[x]==1){d[x]=a[x];return ;}
	LL sum=0,mx=0;
	for(int i=0;i<G[x].size();i++){
		int v=G[x][i];
		if(v==fa)continue;
		dfs(v,x);
		sum+=d[v],mx=max(mx,d[v]);
	}
	d[x]=2*a[x]-sum;
	if(d[x]<0||d[x]>a[x]||mx>a[x])puts("NO"),exit(0);
}

int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(); 
	for(int i=1;i<n;i++){
		int u=read(),v=read();
		du[u]++,du[v]++;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if(n==2){printf("%s",(a[1]!=a[2])?"NO":"YES");return 0;}
	for(int i=1;i<=n;i++)
	if(du[i]!=1)rt=i;
	dfs(rt,0);
	printf("%s",d[rt]?"NO":"YES");
}