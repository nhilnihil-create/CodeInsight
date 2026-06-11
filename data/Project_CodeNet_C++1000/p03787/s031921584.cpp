#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define up(i,j,n)		for(int i=j;i<=n;i++)
#define down(i,j,n)	for(int i=j;i>=n;i--)
#define cmax(a,b)		a=max(a,b)
#define cmin(a,b)		a=min(a,b)
#define Auto(i,node)	for(int i=LINK[node];i;i=e[i].next)

const int MAXN=2e5+5;
const int oo=0x3f3f3f3f;

int N,M,deg[MAXN],col[MAXN];
ll ans=0,a=0,b=0,c=0;
bool vis[MAXN],isbi=0;

namespace Graph{
	struct edge{
		int y,next;
	}e[MAXN<<1];
	int LINK[MAXN],len=0;
	inline void ins(int x,int y){
		e[++len].next=LINK[x];LINK[x]=len;
		e[len].y=y;
	}
	inline void Ins(int x,int y){
		ins(x,y);
		ins(y,x);
		deg[x]++;deg[y]++;
	}
	void DFS(int node){
		vis[node]=1;
		Auto(i,node){
			if(!vis[e[i].y]){
				col[e[i].y]=col[node]*-1;
				DFS(e[i].y);
			}else if(col[e[i].y]!=col[node]*-1)
				isbi=0;
		}
	}
}using namespace Graph;

int main(){
//	freopen("input.in","r",stdin);
	scanf("%d%d",&N,&M);
	up(i,1,M){
		int x,y;
		scanf("%d%d",&x,&y);
		Ins(x,y);
	}
	up(i,1,N)if(!vis[i]){
		if(!deg[i])a++;
		else{
			isbi=1;
			col[i]=1;
			DFS(i);
			if(isbi)c++;
			else b++;
		}
	}
	ans=a*(N-a)+(N-a)*a+a*a+b*b+b*c+c*b+c*c*2;;
	cout<<ans<<endl;
	return 0;
}
