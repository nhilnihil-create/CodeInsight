
// C - Sentou

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

ll t[200000];

int main() {
	int N, T;
	cin >> N >> T;

	for (int i=0; i<N; i++) {
		cin >> t[i];
	}

	ll ans = 0;
	for (int i=0; i<N-1; i++) {
		if (t[i+1] - t[i] < T) {
			ans += (t[i+1] - t[i]);
		} else {
			ans += T;
		}
	}

	ans += T;

	cout << ans << endl;

	return 0;
}