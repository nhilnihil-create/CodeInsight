#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N, K, A, ans = 0;
	static long long SumA[100010] = {}, SumB[100010] = {};
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> A;
		SumA[i + 1] = max(SumA[i], SumA[i] + A);
		SumB[i + 1] = SumB[i] + A;
	}
	long long All = SumA[N];
	for (int i = 0; i <= N - K; i++) {
		ans = max(ans, All - (SumA[i + K] - SumA[i]) + max(SumB[i + K] - SumB[i], (long long)0));
	}
	cout << ans;
}