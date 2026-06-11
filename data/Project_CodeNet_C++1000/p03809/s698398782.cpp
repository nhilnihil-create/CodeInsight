#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
int n;
int a[100007],par[100007],cur[100007],cnt[100007];
int u,v;
vector <int> edge[100007];
void dfs(int u){
	int sum=0,ct=0,mx=0;
	for(int i=0;i<(int)edge[u].size();i++){
		int v=edge[u][i];
		if(v==par[u]) continue;
		par[v]=u;
		dfs(v);
		sum+=a[v];
		mx=max(mx,a[v]);
		ct++;
	}
	if(ct==1 && a[u]!=sum){
		cout<<"NO";
		exit(0);
	}
	else if(ct==1 && a[u]==sum){
		a[u]=sum;
		return;
	}
	else if(ct==0){
		return;
	}
	else if(ct>1 && (sum<a[u] || a[u]*2LL<sum || (mx*2LL>sum && mx>a[u]))){
		cout<<"NO";
		exit(0);
	}
	else if(ct>1){
		a[u]=sum-((sum-a[u])*2LL);
	}
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++){
		cin>>u>>v;
		edge[u].pb(v);
		edge[v].pb(u);
		cnt[u]++;
		cnt[v]++;
	}
	if(n==2){
		if(a[1]==a[2]) cout<<"YES";
		else cout<<"NO";
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(cnt[i]==1){
			par[i]=0;
			dfs(i);
			break;
		}
	}
	cout<<"YES";
}
