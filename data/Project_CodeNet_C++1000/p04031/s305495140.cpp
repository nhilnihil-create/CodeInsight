#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<ll> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	ll ans = 1e9 + 7;
	for(int i = -40000; i < 40000; ++i){
		ll ac = 0;
		for(int j = 0; j < n; ++j){
			ac += ((v[j] - i) * (v[j] - i));
		}
		ans = min(ans, ac);
	}
	cout << ans << '\n';
	return 0;
}