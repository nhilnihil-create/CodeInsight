#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll f[N];
int n,a[N],u,v,i;
vector<int>e[N];
void dfs(int u,int fa){
	if(e[u].size()==1){f[u]=a[u];return;}
	ll su=0,mn,z,y=0;
	for(int v:e[u])if(v!=fa)dfs(v,u),su+=f[v],y=max(y,f[v]);
	if(su-y<y)mn=y,z=y*2-su;else mn=su+1>>1,z=su&1;
	if(a[u]<mn || a[u]>su){
		puts("NO");
		exit(0);
	}
	f[u]=(a[u]-mn)*2+z;
}
int main(){
	scanf("%d",&n);for(i=1;i<=n;++i)scanf("%d",a+i);
	for(i=1;i<n;++i)scanf("%d%d",&u,&v),e[u].push_back(v),e[v].push_back(u);
	if(n==2)return puts(a[1]==a[2]?"YES":"NO"),0;
	for(i=1;e[i].size()==1;++i);dfs(i,0);puts(f[i]?"NO":"YES");
	return 0;
}