#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	ll N, K;
	cin >> N >> K;
	vector<pair<ll, ll>> v(N);
	for(int i = 0; i < N; i++) cin >> v[i].first >> v[i].second;
	sort(v.begin(), v.end());

	for(int i = 0; i < N; i++) {
		K -= v[i].second;
		if(K <= 0) {
			cout << v[i].first << "\n";
			return 0;
		}
	}
	return 0;
}
