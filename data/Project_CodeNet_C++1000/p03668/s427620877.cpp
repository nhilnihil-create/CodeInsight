#include<bits/stdc++.h>
#define pb push_back
#define pp pop_back()
#define mp make_pair
#define fr first
#define sc second
#define sz size()
#define smin(x,y) ((x)=min((x),(y)))
#define smax(x,y) ((x)=max((x),(y)))
#define all(x) x.begin(),x.end()
#define CS ios_base::sync_with_stdio(false);
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi; 
const int M=1e5+5;
vi adj[M];
int dfs(int v,int p=0){
	int ret=0;
	for(int u:adj[v]) if(u!=p) ret^=(dfs(u,v)+1);
	return ret;
}
int32_t main()
{
	int n; cin>>n;
	for(int i=1;i<n;i++){
		int u,v; cin>>u>>v;
		adj[u].pb(v),adj[v].pb(u);
	}
	return cout<<(dfs(1)?"Alice":"Bob")<<endl,0;
}
