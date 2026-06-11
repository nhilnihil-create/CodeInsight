#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

struct Union_find{
	vector<int> par;
	vector<int> rank;
	Union_find(int p){
		par = vector<int>(p + 1);
		rank = vector<int>(p + 1);
		for(int i = 1; i <= p; i++){
			par[i] = i;
		}
	}
	int find(int x){
		if(par[x] == x)
			return x;
		else{
			return par[x] = find(par[x]);
		}
	}
	void unite(int x, int y){
		x = find(x);
		y = find(y);
		if(x == y) return;
		if(rank[x] < rank[y]){
			par[x] = y;
		}else{
			par[y] = x;
			if(rank[x] == rank[y]) rank[x]++;
		}
	}
	bool same(int x, int y){
		return find(x) == find(y);
	}
};


int main(){
	int n, k, l, ans = 0;
	cin >> n >> k >> l;
	Union_find load(n), rail(n);
	for(int i = 0; i < k; i++){
		int x, y;
		cin >> x >> y;
		load.unite(x, y);
	}
	for(int i = 0; i < l; i++){
		int x, y;
		cin >> x >> y;
		rail.unite(x, y);
	}
	vector<pair<int, int>> pa(n + 1);
	map<pair<int, int>, int> ma;
	for(int i = 1; i <= n; i++){
		pa[i].first = load.find(i);
		pa[i].second = rail.find(i);
		ma[pa[i]]++;
	}
	for(int i = 1; i <= n; i++){
		cout << ma[pa[i]];
		if(i < n){
			cout << " ";
		}else{
			cout << endl;
		}
	}
	return 0;
}
