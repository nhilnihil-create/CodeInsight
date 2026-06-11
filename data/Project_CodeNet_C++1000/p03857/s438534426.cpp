#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
ll n, k, l, p, q, r, s, ans[200008];

struct union_find {
	vector<int> rnk, par;
	union_find(int n) {
		rnk.resize(n+1);
		par.resize(n+1);
		for(int i = 1; i <= n; i++){
			par[i] = i;
			rnk[i] = 0;
		}
	}
	
	int find(int x) {
		if (par[x] == x) return x;
		return par[x] = find(par[x]);
	}
 
	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y)return;
		if (rnk[x] < rnk[y]) {
			par[x] = y;
		}
		else {
			par[y] = x;
			if (rnk[x] == rnk[y])rnk[x]++;
		}
	}
	
	bool same(int x, int y) {
		return (find(x) == find(y));
	}
};

int main(){
	cin >> n >> k >> l;
	
	union_find road(n), rail(n);
	for(ll i = 1; i <= k; i++){
		cin >> p >> q;
		road.unite(p, q);
	}
	
	for(ll j = 1; j <= l; j++){
		cin >> r >> s;
		rail.unite(r, s);
	}
	
	map<pair<int, int>, int> ans;
	for(ll i = 1; i <= n; i++){ans[make_pair(road.find(i), rail.find(i))]++;}
	for(ll i = 1; i <= n-1; i++){cout << ans[make_pair(road.find(i), rail.find(i))] << " ";}
	cout << ans[make_pair(road.find(n), rail.find(n))] << endl;
	return 0;
}