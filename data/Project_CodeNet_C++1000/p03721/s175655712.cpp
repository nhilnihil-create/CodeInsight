
// C - Big Array

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int N;
	ll K;
	cin >> N >> K;

	map<int, ll> cnt;

	int a, b;
	for (int i=0; i<N; i++) {
		cin >> a >> b;
		cnt[a] += b;
	}

	int ans;
	ll cum_cnt = 0;
	for (auto itr = cnt.begin(); itr != cnt.end(); itr++) {
		cum_cnt += itr->second;
		if (cum_cnt >= K) {
			ans = itr->first;
			break;
		}
	}

	cout << ans << endl;

	return 0;
}