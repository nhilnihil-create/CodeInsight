
// B - Simplified mahjong

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

ll A[100000];

int main() {
	int N;
	cin >> N;

	for (int i=0; i<N; i++) {
		cin >> A[i];
	}

	ll ans = A[0] / 2;
	A[0] -= (A[0] / 2) * 2;

	for (int i=1; i<N; i++) {
		ll p1 = min(A[i-1], A[i]);
		A[i] -= p1;

		ll p2 = A[i] / 2;
		A[i] -= p2 * 2;

		ans += p1 + p2;
	}

	cout << ans << endl;

	return 0;
}