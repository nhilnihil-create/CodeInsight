#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll H, W, N; cin >> H >> W >> N;
	map<pair<ll, ll>, ll> m;
	for(int i = 0; i < N; ++i){
		ll a, b; cin >> a >> b;
		for(int j = -1; j <= 1; ++j){
			for(int k = -1; k <= 1; ++k){
				if(a + j <= 1 || a + j > H - 1 || b + k <= 1 || b + k > W - 1) continue;
				++m[pair<ll, ll>(a + j, b + k)];
			}
		}
	}
	ll ans[10] = {(H - 2) * (W - 2) - (ll)m.size()};
	for(auto ite = m.begin(); ite != m.end(); ++ite) ++ans[ite->second];
	for(int i = 0; i < 10; ++i) cout << ans[i] << endl;
	return 0;
}