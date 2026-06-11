#include<bits/stdc++.h>
using namespace std;
const int N=100100;
int n,K,fa[N],ans,mx[N];
vector<int>g[N];
void dfs(int x){
	mx[x]=1;
	for(int i:g[x]){
		dfs(i);
		if(mx[i]>=K&&x!=1)++ans;
		else mx[x]=max(mx[x],mx[i]+1);
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>K;
	for(int i=1;i<=n;++i)cin>>fa[i];
	if(fa[1]!=1)fa[1]=1,++ans;
	for(int i=2;i<=n;++i)g[fa[i]].push_back(i);
	dfs(1);
	cout<<ans<<'\n';
	return 0;
}
