#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

const ll INF = 100100100100;

int main() {
	int N, K;
	cin >> N >> K;

	vector <ll> a(N);
	for (int ii = 0; ii < N; ++ii){
		cin >> a[ii];
	}

	ll ans = INF;
	for (int n = 0; n < (1<<N); ++n){
		bitset< 1<<15 > bs(n);
		if (bs.count()!=K) continue;

		ll sum = 0;
		ll h = a[0];
		for (int ii = 1; ii < N; ++ii){
			if (bs[ii]){
				ll need;
				if (h < a[ii]){
					h = a[ii];
					need = 0;
				} else {
					h += 1;
					need = h - a[ii];
				}
				sum += need;
			} else {
				h = max(h, a[ii]);
			}
		}
		ans = min(ans, sum);
	}

	cout << ans << "\n";

	return 0;
}
