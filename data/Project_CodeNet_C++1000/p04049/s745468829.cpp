#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=2e3+2;
int n,k,res;
struct Edge{
	int to,nxt;
};
Edge edge[maxn<<1];
int cnt,head[maxn];
void addedge(int u,int v){
	cnt++;
	edge[cnt].to=v;
	edge[cnt].nxt=head[u];
	head[u]=cnt;
}
int dfs(int u,int fa,int dep){
	int sum=1;
	if (dep!=k/2)
		for (int i=head[u];~i;i=edge[i].nxt){
			int v=edge[i].to;
			if (v==fa) continue;
			sum+=dfs(v,u,dep+1);
		}
	return sum;
}
void init(){
	cnt=0;
	memset(head,-1,sizeof(head));
}
int main(){
	init();
	scanf("%d%d",&n,&k);
	for (int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	if (k&1)
		for (int u=1;u<=n;u++)
			for (int i=head[u];~i;i=edge[i].nxt){
				int v=edge[i].to;
				res=max(res,dfs(u,v,0)+dfs(v,u,0));
			}
	else
		for (int u=1;u<=n;u++)
			res=max(res,dfs(u,-1,0));
	printf("%d",n-res);
	return 0;
}