
// B - Buildings are Colorful!

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

ll a[15];

int count_bit(int bit, int N) {
	int result = 0;

	for (int i=0; i<N; i++) {
		if (bit & (1<<i)) result++;
	}

	return result;
}

ll solve(int bit, int N) {
	ll result = 0;
	ll min_height = a[0] + 1;

	for (int i=1; i<N; i++) {
		if (bit & (1<<i)) {
			if (a[i] < min_height) {
				result += (min_height - a[i]);
			}

			min_height = max(min_height + 1, a[i] + 1);
		} else {
			min_height = max(min_height, a[i] + 1);
		}
	}

	return result;
}

int main() {
	int N, K;
	cin >> N >> K;

	for (int i=0; i<N; i++) {
		cin >> a[i];
	}

	ll ans = INF;

	for (int bit=0; bit < (1<<N); bit++) {
		if (count_bit(bit, N) == K) {
			//cout << bitset<15>(bit) << endl; // **** debug ****
			ans = min(ans, solve(bit, N));
		}
	}

	cout << ans << endl;

	return 0;
}