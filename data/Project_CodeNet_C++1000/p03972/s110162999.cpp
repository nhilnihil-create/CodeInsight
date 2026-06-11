#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;
const ll INF = 1e18+7;

signed main(){
	int h, w;
	cin >> h >> w;
	vector<int> a(h), b(w);
	for(auto& x : a)
		cin >> x;
	for(auto& x : b)
		cin >> x;

	vector<int> t = {h + 1, w + 1};
	vector<pair<int,int>> p;
	for(int i = 0; i < h; ++i)
		p.emplace_back(a[i], 0);
	for(int i = 0; i < w; ++i)
		p.emplace_back(b[i], 1);
	sort(p.begin(), p.end());

	ll ans = 0;

	for(auto& q : p){
		int x, y;
		tie(x, y) = q;
		ans += 1LL * t[!y] * x;
		--t[y];
	}
	cout << ans << endl;
}
