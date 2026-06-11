#include <bits/stdc++.h>
using namespace std;
const int maxn = 2345;
int upto[maxn][maxn], sz[maxn], k;
vector<int> e[maxn];
vector<pair<int,int> > eds;
int count(int u, int v, int d){
	if(d < 0) return 0;
	int ans = 1;
	for(int nxt : e[u]) if(nxt != v) ans += count(nxt, u, d - 1);
	return ans;
}
int main(){
	int n; cin >> n >> k;
	for(int i = 0; i < n - 1; i++){
		int x, y; 
		cin >> x >> y;
	       	eds.push_back({x, y});	
		e[x].push_back(y); 
		e[y].push_back(x);
	}
	int res = 0;
	for(int i = 1; i <= n; i++) {
		res = max(res, count(i, 0, k/2));
	}
	for(auto e : eds){
		res = max(res, count(e.first, e.second, (k - 1)/2) + count(e.second, e.first, (k - 1)/2));
	}
	cout << n - res << endl;
	return 0;
}
