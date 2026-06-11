#include <bits/stdc++.h>
using namespace std;
int main(){
	int w, h; cin >> w >> h;
	vector<pair<int,int> > e;
	for(int i = 0; i < w; i++){
		int x; cin >> x;
		e.push_back({x, 0});
	}
	for(int i = 0; i < h; i++){
		int x; cin >> x;
		e.push_back({x, 1});
	}
	long long ans = 0;
	int cw = 0, ch = 0;
	sort(e.begin(), e.end());
	for(auto p : e){
		int x, o; tie(x, o) = p;
		if(o){
			ans += 1ll * (w - cw + 1) * x;
			ch++;
		} else {
			ans += 1ll * (h - ch + 1) * x;
			cw++;
		}
	}
	cout << ans << endl;
	return 0;
}
