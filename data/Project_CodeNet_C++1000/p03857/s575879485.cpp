#include <bits/stdc++.h>

using namespace std;
using llong = long long;
using ldbl = long double;
using P = pair<llong, llong>;

#define BE(x) x.begin(), x.end()

const llong inf = llong(1e18)+7;
const llong mod = 1e9+7;

struct Unifind{
	vector<int> par;

	Unifind(){}
	Unifind(int n) :
		par(n+1, -1)
	{}
	int root(int x){
		if(par[x] < 0) return x;
		return par[x] = root(par[x]);
	}
	int size(int x){
		return -par[root(x)];
	}
	bool same(int a, int b){
		return root(a) == root(b);
	}
	bool marge(int a, int b){
		a = root(a), b = root(b);
		if(a == b) return false;
		if(par[a] > par[b]) swap(a, b);
		par[a] += par[b];
		par[b] = a;
		return true;
	}
};

int main(){
	llong N, K, L;
	cin >> N >> K >> L;

	Unifind road(N), train(N);
	int p,q;
	for(int i = 0; i < K; i++){
		cin >> p >> q;
		road.marge(p,q);
	}
	int r,s;
	for(int i = 0; i < L; i++){
		cin >> r >> s;
		train.marge(r,s);
	}

	map<P,int> m;
	for(int i = 1; i <= N; i++)
		m[P(road.root(i), train.root(i))]++;

	for(int i = 1; i <= N; i++)
		cout << m[P(road.root(i), train.root(i))] << " ";
	cout << endl;

	return 0;
}