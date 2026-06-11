#include <bits/stdc++.h>
using namespace std;

#define MAX 100000

int main() {
	long long N, A[MAX], cum[MAX];
	int ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A, A + N);
	cum[0] = A[0];
	for (int i = 1; i < N; i++) {
		cum[i] = cum[i - 1] + A[i];
	}
	ans++;	// Max A[i] creature can eat every other creature
	for (int i = N - 2; i >= 0; i--) {
		if (2 * cum[i] >= A[i + 1]) {
			ans++;
		} else {
			break;
		}
	}
	cout << ans << endl;
	return 0;
}