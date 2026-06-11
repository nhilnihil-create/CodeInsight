#include <bits/stdc++.h>
using namespace std;
using Int = int_fast64_t;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	Int w, h; cin >> w >> h;
	using P = pair<Int, bool>;
	priority_queue<P, vector<P>, greater<>> pq;
	for(Int i=0; i<w; ++i){
		Int p; cin >> p;
		pq.push(P(p, 0));
	}
	for(Int i=0; i<h; ++i){
		Int q; cin >> q;
		pq.push(P(q, 1));
	}
	Int a = h+1, b = w+1, c = 0, ans = 0;
	while(c < w*h+w+h){
		P p = pq.top(); pq.pop();
		if(!p.second){
			Int t = min(a, w*h+w+h-c);
			ans += p.first * t;
			c += t;
			--b;
		}else{
			Int t = min(b, w*h+w+h-c);
			ans += p.first * t;
			c += t;
			--a;
		}
	}
	cout << ans << "\n";
}