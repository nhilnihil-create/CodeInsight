#include <bits/stdc++.h>
using namespace std;
using Int = int_fast64_t;

Int n;
vector<vector<Int>> a;
vector<Int> v;

Int rec(Int p){
	if(v[p] != -1) return v[p];
	if(a[p].size() == 0) return v[p] = 0;
	vector<Int> w(a[p].size());
	for(size_t i=0; i<a[p].size(); ++i)
		w[i] = rec(a[p][i]);
	sort(w.begin(), w.end());
	Int res = 0;
	for(size_t i=0; i<w.size(); ++i)
		res = max<Int>(res, w[i]+w.size()-i);
	return v[p] = res;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	a.resize(n);
	for(Int i=0; i<n-1; ++i){
		Int t;
		cin >> t;
		a[t-1].push_back(i+1);
	}
	v.resize(n, -1);
	for(Int i=0; i<n; ++i)
		v[i] = rec(i);
	cout << v[0] << "\n";
}