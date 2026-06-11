#include <bits/stdc++.h>
using namespace std;

int n, k, l;
typedef pair<int, int> P;
map<P, int> mp;
class UnionFind{
	public:
		vector<int> Parent;
		vector<int> Rank;
		UnionFind(int n){
			++n;
			Parent.resize(n, 0);
			Rank.resize(n, 0);
			for(int i=0; i<n; ++i)
				Parent[i] = i;
		}

		int find(int x){
			if(Parent[x] == x) return x;
			return Parent[x] = find(Parent[x]);
		}

		void unite(int x, int y){
			x = find(x);
			y = find(y);
			if(x == y) return;
			if(Rank[x] < Rank[y]) Parent[x] = y;
			else{
				Parent[y] = x;
				if(Rank[x] == Rank[y]) ++Rank[x];
			}
		}

		bool same(int x, int y){
			return find(x) == find(y);
		}
};

int main(){
//	cin.tie(0);
//	ios::sync_with_stdio(false);
	cin >> n >> k >> l;
	UnionFind ufa(n), ufc(n);
	for(int i=0; i<k; ++i){
		int p, q;
		cin >> p >> q;
		ufa.unite(p, q);
	}
	for(int i=0; i<l; ++i){
		int r, s;
		cin >> r >> s;
		ufc.unite(r, s);
	}
	for(int i=1; i<=n; ++i){
		P p = P(ufa.find(i), ufc.find(i));
		if(mp.find(p) == mp.end()) mp[p] = 1;
		else ++mp[p];
	}
	for(int i=1; i<=n; ++i)
		cout << mp[P(ufa.find(i), ufc.find(i))] << (i == n ? "\n" : " ");
}