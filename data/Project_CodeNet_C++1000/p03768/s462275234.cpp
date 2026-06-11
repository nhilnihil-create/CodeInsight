#pragma GCC optimize("-Ofast","-funroll-all-loops")
#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=1e5+10;
int n,m,q,a[N],b[N],c[N],col[N][12];
vector<int> g[N];
void dfs(int x,int dep,int id){
	if(dep<0||col[x][dep]) return ;
	col[x][dep]=max(col[x][dep],id);
	for(int to:g[x]) dfs(to,dep-1,id);
}
signed main(){
	cin>>n>>m;
	for(int i=1,a,b;i<=m;i++) scanf("%d %d",&a,&b),g[a].push_back(b),g[b].push_back(a);
	cin>>q;
	for(int i=1;i<=q;i++) scanf("%d %d %d",&a[i],&b[i],&c[i]);
	for(int i=q;i>=1;i--) dfs(a[i],b[i],i);
	for(int i=1;i<=n;i++){
		int ans=0;
		for(int j=0;j<=10;j++)	ans=max(ans,col[i][j]);
		printf("%d\n",c[ans]);
	}
	return 0;
}
