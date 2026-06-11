#include "bits/stdc++.h"

using namespace std;

int main() {
	int N, K, X, Y;
	cin >> N >> K >> X >> Y;
	int ans = 0;
	if (N>K) {
		ans = (N - K)*Y + K * X;
	}
	else {
		ans = N * X;
	}
	cout << ans << endl;
	return 0;
}
