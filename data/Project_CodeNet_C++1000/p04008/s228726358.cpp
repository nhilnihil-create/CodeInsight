#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=100005;

int ans,n,k;
bool vis[MAXN];
vector<int> E[MAXN];

int dfs(int u,int f){
	int re=0;
	for(int i=0;i<(int)E[u].size();i++){
		int v=E[u][i];
		if(v!=f){
			re=max(re,dfs(v,u));
		}
	}
	re++;
	if(vis[u]==0&&re>=k){
		re=0;
		ans++;
	}
	return re;
}

int main(){
	scanf("%d %d",&n,&k);
	int a;
	scanf("%d",&a);
	if(a!=1)
		ans=1;
	for(int i=2;i<=n;i++){
		scanf("%d",&a);
		E[a].push_back(i);
		E[i].push_back(a);
		if(a==1)
			vis[i]=1;
	}
	vis[1]=1;
	dfs(1,0);
	printf("%d\n",ans);
}