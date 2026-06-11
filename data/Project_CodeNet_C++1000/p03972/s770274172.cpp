#include <bits/stdc++.h>
using namespace std;
using Int = int_fast64_t;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	Int w, h; cin >> w >> h;
	using P = pair<Int, bool>;
	vector<P> v;
	for(Int i=0; i<w; ++i){
		Int p; cin >> p;
		v.push_back(P(p, 0));
	}
	for(Int i=0; i<h; ++i){
		Int q; cin >> q;
		v.push_back(P(q, 1));
	}
	sort(v.begin(), v.end());
	Int a = h+1, b = w+1, c = 0, ans = 0, e = w*h+w+h;
	for(size_t i=0; i<v.size() && c < e; ++i){
		P p = v[i];
		if(!p.second){
			Int t = min(a, e-c);
			ans += p.first * t;
			c += t;
			--b;
		}else{
			Int t = min(b, e-c);
			ans += p.first * t;
			c += t;
			--a;
		}
	}
	cout << ans << "\n";
}