#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>e[N];
int n,m,i,u,v,a[N],x,y,z,sz;
int dfs(int x,int v){
	int ans=1;a[x]=v;++sz;
	for(int y:e[x])if(a[y]==-1)ans&=dfs(y,v^1);else ans&=a[x]!=a[y];
	return ans;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;for(i=1;i<=m;++i)cin>>u>>v,e[u].push_back(v),e[v].push_back(u);
	memset(a+1,-1,n<<2);for(i=1;i<=n;++i)if(a[i]==-1)sz=0,y+=dfs(i,0),++z,x+=sz==1;
	y-=x;z-=x;
	cout<<1ll*y*y+1ll*z*z+2ll*x*n-1ll*x*x<<endl;
	return 0;
}