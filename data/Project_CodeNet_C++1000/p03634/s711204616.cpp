#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 100005;
const int LGN = 18;

vector<int> g[N];
int a[N], b[N], c[N];
ll d[N];

void dfs(int v, int par = 0, ll __dist = 0){
	d[v] = __dist;
	for(auto ind : g[v]){
		int u = a[ind]^b[ind]^v;
		if(u != par){
			dfs(u, v, __dist + c[ind]);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n; cin>>n;
	for(int i = 1; i < n; i++){
		cin>>a[i]>>b[i]>>c[i];
		g[a[i]].push_back(i);
		g[b[i]].push_back(i);
	}
	int q, k;
	cin>>q>>k;
	dfs(k);
	while(q--){
		int u, v;
		cin>>u>>v;
		cout<<d[u] + d[v]<<'\n';
	}

	return 0;
}