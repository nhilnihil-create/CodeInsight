#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
#define pb push_back
int n,m,a,b;
bool used[111111];
vector<int>v[111111],ans;
void dfs(int x){
	used[x]=true;
	ans.pb(x);
	for(int i:v[x]){
		if(!used[i]){
			dfs(i);
			return;
		}
	}
}
signed main(){
	cin>>n>>m;
	rep(i,m){
		cin>>a>>b;
		v[a-1].pb(b-1);
		v[b-1].pb(a-1);
	}
	dfs(0);
	reverse(ans.begin(),ans.end());
	for(int i:v[0]){
		if(!used[i]){
			dfs(i);
			break;
		}
	}
	cout<<ans.size()<<endl;
	rep(i,ans.size())cout<<ans[i]+1<<(i==ans.size()-1?"\n":" ");
	return 0;
}
