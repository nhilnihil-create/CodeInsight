#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)
constexpr int mod=1000000007;
constexpr int mod1=998244353;
vector<int> dx={0,1,0,-1},dy={-1,0,1,0};
bool inside(int y,int x,int h,int w){
	if(y<h && y>=0 && x<w && x>=0) return true;
	return false;
}


struct UnionFind{
	vector<int> par;
	vector<int> rank;
	
	UnionFind(int n){
		par.resize(n);
		rank.resize(n);
		rep(i,n) par.at(i) = i;
	}
	
	int find(int x){
		if(par.at(x) == x) return x;
		else return par.at(x) = find(par.at(x));
	}
	
	bool unite(int x, int y){
		x = find(x);
		y = find(y);
		if(x == y) return false;
		else{
			par.at(y) = x;
			if(rank.at(x) == rank.at(y)) rank.at(x)++;
		}
		return true;
	}
};


int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n,t,l;cin >> n >> t >> l;
	UnionFind uf1 = UnionFind(n), uf2 = UnionFind(n);
	rep(i,t){
		int p,q;cin >> p >> q;
		p--;q--;
		uf1.unite(p,q);
	}
	rep(i,l){
		int r,s;cin >> r >> s;
		r--;s--;
		uf2.unite(r,s);
	}
	map<pii,int> m;
	vector<int> ans(n);
	rep(i,n) m[mp(uf1.find(i), uf2.find(i))]++;
	rep(i,n) ans.at(i) = m[mp(uf1.find(i), uf2.find(i))];
	rep(i,n){
		if(i == n - 1) cout << ans.at(i) << endl;
		else cout << ans.at(i) << " ";
	}
}
