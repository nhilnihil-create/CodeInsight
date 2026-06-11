
// B - Minimum Sum

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int a[200000];
int pos[200001];

int main() {
	int N;
	cin >> N;

	for (int i=0; i<N; i++) {
		cin >> a[i];
		pos[a[i]] = i; // a[i]の位置を記録
	}

	ll ans = 0;
	set<int> pos_set;
	for (int i=1; i<=N; i++) {
		int k = pos[i];

		ll l, r;
		auto itr = pos_set.lower_bound(k);

		if (itr == pos_set.end()) {
			r = N - 1;
		} else {
			r = *itr - 1;
		}

		if (itr == pos_set.begin()) {
			l = 0;
		} else {
			itr--;
			l = *itr + 1;
		}

		// cout << l << " " << k << " " << r << endl; // **** debug ****

		ans += i * (k - l + 1) * (r - k + 1); // i * (minがiとなる選び方の数)

		pos_set.insert(k);
	}

	cout << ans << endl;

	return 0;
}