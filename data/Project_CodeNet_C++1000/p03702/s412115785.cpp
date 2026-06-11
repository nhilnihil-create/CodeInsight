#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, A, B;
vector<ll> H;
// c回クエリを実行したときに要件を満たすか
bool f(ll c) {
	vector<ll> rest = H;
	for(int i=0;i<N;i++) {
		rest[i] = max(rest[i] - B * c, 0LL);
	}
	ll cnt = 0;
	for(int i=0;i<N;i++) {
		if(rest[i] == 0) continue;
		cnt += ((rest[i] + (A - B) - 1) / (A - B));
	}
	return ((cnt <= c) ? true : false);
}

signed main() {
	cin >> N >> A >> B;
	H.resize(N);
	for(auto &h : H) cin >> h;
	ll left = 0LL, right = (ll)1e9+7;
	while(right - left > 1) {
		ll mid = (left + right) >> 1LL;
		if(f(mid)) right = mid;
		else left = mid;
	}
	cout << right << endl;
}