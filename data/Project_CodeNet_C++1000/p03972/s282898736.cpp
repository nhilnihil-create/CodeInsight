#include <bits/stdc++.h>
using namespace std;
using Int = int_fast64_t;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	Int w, h, ans = 0; cin >> w >> h;
	priority_queue<pair<Int, bool>> pq;
	for(Int i=0; i<w; ++i){
		Int p; cin >> p;
		pq.push(make_pair(p, 0));
		ans += p * (h+1);
	}
	for(Int i=0; i<h; ++i){
		Int q; cin >> q;
		pq.push(make_pair(q, 1));
		ans += q * (w+1);
	}
	Int rw = w, rh = h, ne = (h+1)*w + (w+1)*h;
	while(ne > (w+1)*(h+1) - 1){
		pair<Int, bool> p = pq.top(); pq.pop();
		if(!p.second){
			Int de = min(rh, ne-w*h+1);
			ne -= de;
			ans -= de * p.first;
			--rw;
		}else{
			Int de = min(rw, ne-w*h+1);
			ne -= de;
			ans -= de * p.first;
			--rh;
		}
	}
	cout << ans << "\n";
}