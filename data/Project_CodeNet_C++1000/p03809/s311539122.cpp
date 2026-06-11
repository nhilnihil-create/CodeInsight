#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int N=200005;
int n,rt,a[N],o[N];
vector<int>e[N];
void dfs(int u,int fa){
	if(e[u].size()==1){o[u]=a[u];return;}
	int mx=0,sum=0;
	for(int i=0,v;i<e[u].size();++i)
		if((v=e[u][i])!=fa)
			dfs(v,u),sum+=o[v],mx=max(mx,o[v]);
	o[u]=2*a[u]-sum;
	if(o[u]<0||o[u]>a[u]||a[u]<mx)puts("NO"),exit(0);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	if(n==2)puts(a[1]==a[2]?"YES":"NO"),exit(0);
	for(int i=1,u,v;i<n;++i)
		scanf("%d%d",&u,&v),
		e[u].push_back(v),e[v].push_back(u);
	for(int i=1;i<=n;++i)
		if(e[i].size()>1)rt=i;
	dfs(rt,0),puts(o[rt]?"NO":"YES");
	return 0;
}