#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1012345678;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<long long> SA(N + 1), SB(N + 1);
	for (int i = 0; i < N; ++i) {
		SA[i + 1] = SA[i] + A[i];
		SB[i + 1] = SB[i] + max(A[i], 0);
	}
	long long ans = 0;
	for (int i = 0; i <= N - K; ++i) {
		long long preval = SB[i] + (SB[N] - SB[i + K]);
		ans = max(ans, preval + max(SA[i + K] - SA[i], 0LL));
	}
	cout << ans << endl;
	return 0;
}