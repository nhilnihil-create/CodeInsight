
// C - Lining Up

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
const ll MOD = 1e9 + 7;

int A[100000];

int main() {
	int N;
	cin >> N;

	for (int i=0; i<N; i++) {
		cin >> A[i];
	}

	sort(A, A+N);

	ll ans = 1;
	if (N % 2 == 0) {
		for (int i=0; i<N; i++) {
			if (i % 2 == 0) {
				if (A[i] != A[i+1]) {
					ans = 0;
					break;
				}

				ans = ans * 2 % MOD;
			}
		}
	} else {
		for (int i=0; i<N; i++) {
			if (i % 2 == 1) {
				if (A[i] != A[i+1]) {
					ans = 0;
					break;
				}

				ans = ans * 2 % MOD;
			}
		}
	}

	cout << ans << endl;

	return 0;
}