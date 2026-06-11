#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	if (2<= abs(N-M)) {
		cout << 0<<endl;
		return 0;
	}
	long long ans = 1;
	for (long long i = 1;i<=M;++i) {
		ans *= i;
		ans %= 1000000007;
	}
	for (long long i = 1;i<=N;++i) {
		ans *= i;
		ans %= 1000000007;
	}
	if (N==M) {
		ans *= 2;
		ans %= 1000000007;
	}
	cout << ans << endl;
	return 0;
}