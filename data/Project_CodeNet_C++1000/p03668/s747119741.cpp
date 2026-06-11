#include<bits/stdc++.h>
using namespace std;
const int N=100005;
vector<int>e[N];
int f[N],n,i,x,y;
void dfs(int x,int fa){
	for(int i=0;i<e[x].size();++i)
		if(e[x][i]!=fa)dfs(e[x][i],x),f[x]^=f[e[x][i]]+1;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(i=1;i<n;++i)cin>>x>>y,e[x].push_back(y),e[y].push_back(x);
	dfs(1,0);
	cout<<(f[1]?"Alice\n":"Bob\n");
	return 0;
}