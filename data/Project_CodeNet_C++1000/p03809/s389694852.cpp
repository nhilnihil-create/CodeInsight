#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#define SF scanf
#define PF printf
#define MAXN 100010
typedef long long ll;
using namespace std;
int n;
vector<int> a[MAXN];
ll val[MAXN];
int u,v;
ll dfs(int x,int fa){
	ll sum=0,mx=0;
	if(a[x].size()==1&&fa!=0)
		return val[x];
	for(int i=0;i<int(a[x].size());i++){
		int u=a[x][i];
		if(u==fa)
			continue;
		ll s=dfs(u,x);
		mx=max(mx,s);
		sum+=s;
	}
	if(sum<val[x]||sum>val[x]*2){
		PF("NO");
		exit(0);
	}
	ll nx=2ll*val[x]-sum;
	if((sum-nx)/2ll<mx-nx){
		PF("NO");
		exit(0);	
	}
	return 2ll*val[x]-sum;
}
int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	SF("%d",&n);
	for(int i=1;i<=n;i++)
		SF("%lld",&val[i]);
	for(int i=1;i<n;i++){
		SF("%d%d",&u,&v);	
		a[u].push_back(v);
		a[v].push_back(u);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(a[i].size()==1){
			ans=(dfs(i,0)==val[i]);
			break;
		}
	if(ans==0)
		PF("NO");
	else
		PF("YES");
}