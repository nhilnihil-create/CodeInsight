#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>e[N];
int f[N],n,i,a;
void dfs(int u){
	for(int&v:e[u])dfs(v),v=f[v];
	sort(e[u].begin(),e[u].end());
	for(int i=0,a=e[u].size();i<a;++i)f[u]=max(f[u],a-i+e[u][i]);
}
int main(){
	scanf("%d",&n);
	for(i=2;i<=n;++i)scanf("%d",&a),e[a].push_back(i);
	dfs(1);printf("%d\n",f[1]);
	return 0;
}