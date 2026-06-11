//#pragma GCC optimize(3)
#include<iostream>
#include<iomanip>
#include<stack>
#include<queue>
#include<list>
#include<vector>
#include<set> 
#include<map>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#define ll long long
#define db double
#define inf 200009
#define infm 800009
#define INF (int)1e9
#define mod 1000000007LL
#define pi acos(-1)
#define rd(n) {n=0;char ch;int f=0;do{ch=getchar();if(ch=='-'){f=1;}}while(ch<'0'||ch>'9');while('0'<=ch&&ch<='9'){n=(n<<1)+(n<<3)+ch-48;ch=getchar();}if(f)n=-n;}
using namespace std;
int n,k;

struct edge{
	int nxt,y;
	edge(){}
	edge(int nn,int yy){
		nxt=nn,y=yy;
	}
}e[inf*2];
int head[inf],ecnt;

void addedge(int x,int y){
	ecnt++;
	e[ecnt]=edge(head[x],y);
	head[x]=ecnt;
	return;
}

int ans=0;
int fa[inf];

int dfs(int u,int dep){
	int mxdep=dep;
	for (int i=head[u];i;i=e[i].nxt){
		int v=e[i].y;
		mxdep=max(mxdep,dfs(v,dep+1));
	}
	if (mxdep-dep==k-1 && fa[u]!=1){
	    ans++;
	    return 0;
	}
	return mxdep;
}

int main(){
	rd(n) rd(k)
	for (int i=1;i<=n;i++){
		rd(fa[i])
		if (i!=1){
			addedge(fa[i],i);
		}
		else{
			ans+=(fa[i]!=1);
		}
	}
	for (int i=head[1];i;i=e[i].nxt){
		int v=e[i].y;
		dfs(v,0);
	}
	printf("%d",ans);
	return 0;
}