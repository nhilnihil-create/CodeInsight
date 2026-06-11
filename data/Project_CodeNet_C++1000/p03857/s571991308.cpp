#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define RREP(i,a,b) for(int i=(a);i>=(b);i--)
#define pq priority_queue
#define P pair<int,int>
#define P2 pair<int,P>
#define P3 pair<int,P2>
typedef long long ll; typedef long double ld;
using namespace std;
const int INF=1e9, MOD=1e9+7, around[]={0,1,1,-1,-1,0,-1,1,0,0};
const ll LINF=1e18;
const ld PI=abs(acos(-1));

struct UnionFind{
	vector<int> data;
	
	UnionFind(int sz){
		data.assign(sz, -1);
	}
	
	bool unite(int x, int y){
		x = find(x); y = find(y);
		if(x == y) return false;
		if(data[x] > data[y]) swap(x, y);
		data[x] += data[y];
		data[y] = x;
		return true;
	}
	
	int find(int k){
		if(data[k] < 0) return k;
		else return data[k] = find(data[k]);
	}
	
	bool same(int x, int y){
		if(find(x) == find(y)) return true;
		else return false;
	}
	
	int size(int k){
		return -data[find(k)];
	}
};

int n,A,B;

int main(){
	cin >> n >> A >> B;
	
	UnionFind uf1(n), uf2(n);
	REP(i,0,A){
		int a,b; cin >> a >> b;  a--; b--;
		uf1.unite(a, b);
	}
	
	REP(i,0,B){
		int a,b; cin >> a >> b; a--; b--;
		uf2.unite(a, b);
	}
	
	vector<P> vec;
	REP(i,0,n) vec.push_back({uf1.find(i), uf2.find(i)});
	sort(vec.begin(), vec.end());
	
	REP(i,0,n){
		P p = P(uf1.find(i), uf2.find(i));
		int pos = upper_bound(vec.begin(), vec.end(), p) - lower_bound(vec.begin(), vec.end(), p);
		cout << pos << " ";
	} cout << endl;
	return 0;
}
