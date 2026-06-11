#include <bits/stdc++.h>
using namespace std;

typedef long long lint;
typedef pair<int, int> pii;

const int MAX = 200010;
const int INF = 2e9 + 10;
const int MOD = 1e9 + 7;
const lint LNF = 2e18 + 10;

int n;
vector<int> G[MAX];

int dfs(int v, int p=0){
	int res = 0;
	for(int x:G[v]) if(x!=p) res ^= 1+dfs(x,v);
	return res;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);

	cin>>n;
	for(int i=1; i<n; i++){
		int u,v; cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	cout<<(dfs(1) == 0 ? "Bob" : "Alice")<<'\n';

	return 0;
}
