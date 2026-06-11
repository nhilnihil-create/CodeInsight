#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

#define sz(x) (int)(x.size())
#define fr(i,a,b) for(int i=a;i<b;++i)
#define pb push_back
/////////////////

int const N = 2e5 + 41;

int n;
vector<int> e[N];

int dfs(int u, int p){
	int r = 0;
	fr(i, 0, sz(e[u])){
		int to = e[u][i];
		if(to == p) continue;
		r ^= (dfs(to, u) + 1);
	}
	return r;
}

void solve(){
	cin >> n;
	fr(i, 0, n-1){
		int u, v;
		cin >> u >> v;
		--u;--v;
		e[u].pb(v);
		e[v].pb(u);
	}
	if(dfs(0, -1)) cout << "Alice";
	else cout << "Bob";
	cout << endl;
}

int main(){
#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	solve();

	return 0;
}