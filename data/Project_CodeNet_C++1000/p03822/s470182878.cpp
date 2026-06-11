#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int dfs(int v, vector<vector<int>> &g){
	if(g[v].empty()) return 1;
	int res = 1;
	vector<int> w;
	for(auto nv : g[v]){
		w.push_back(dfs(nv, g));
	}
	sort(w.begin(), w.end());
	int m = w.size();
	rep(i,m){
		chmax(res, m-i+w[i]);
	}
	return res;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	rep(i,n-1){
		int a;
		cin >> a;
		--a;
		g[a].push_back(i+1);
	}
	int ans = dfs(0, g) - 1;
	cout << ans << endl;
	return 0;
}
