#include<bits/stdc++.h>
using namespace std;
typedef pair<int,long long> pi;
long long dist[100005];
vector<pi>tree[100005];
bool visited[100005];
void dfs(int curr,long long d){
	dist[curr] = d;
	visited[curr] = true;
	for(int i=0; i<tree[curr].size(); i++){
		int child = tree[curr][i].first;
		long long len = tree[curr][i].second;
		if(!visited[child]) dfs(child,d+len);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=1; i<n; i++){
		int a,b;
		long long d;
		cin>>a>>b>>d;
		tree[a].push_back(pi(b,d));
		tree[b].push_back(pi(a,d));
	}
	int q,k;
	cin>>q>>k;
	dfs(k,0);
	while(q--){
		int a,b;
		cin>>a>>b;
		cout<<dist[a]+dist[b]<<'\n';
	}
}