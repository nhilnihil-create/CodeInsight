
// A - Multiple Array

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

ll A[100000];
ll B[100000];

int main() {
	int N;
	cin >> N;

	for (int i=0; i<N; i++) {
		cin >> A[i] >> B[i];
	}

	ll cnt = 0;

	for (int i=N-1; i>=1; i--) {
		if (A[i] % B[i] > 0) cnt += B[i] - (A[i] % B[i]);
		A[i-1] += cnt;
	}

	if (A[0] % B[0] > 0) cnt += B[0] - (A[0] % B[0]);

	ll ans = cnt;

	cout << ans << endl;

	return 0;
}