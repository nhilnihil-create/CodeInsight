#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int Mod = 1000000007;
int main() {
	int N;
	cin >> N;
	vector<int> T(N), A(N);
	vector<long long>MIN(N), MAX(N);
	for (int i = 0; i < N; i++) cin >> T[i];
	for (int i = 0; i < N; i++) cin >> A[i];
	MIN[0] = T[0];
	MAX[0] = T[0];
	for (int i = 1; i < N; i++) {
		if (T[i] > T[i - 1]) {
			MIN[i] = T[i];
			MAX[i] = T[i];
		}
		else {
			MAX[i] = MAX[i - 1];
			MIN[i] = 1ll;
		}
	}
	MIN[N - 1] = max(MIN[N - 1], (long long)A[N - 1]);
	MAX[N - 1] = min(MAX[N - 1], (long long)A[N - 1]);
	for (int i = N - 2; i >= 0; i--) {
		if (A[i] > A[i + 1]) {
			MIN[i] = A[i];
			MAX[i] = A[i];
		}
		else {
			MAX[i] = min(MAX[i], MAX[i + 1]);
			MIN[i] = max(MIN[i], 1ll);
		}
	}
	long long ans = 1;
	for (int i = 0; i < N; i++) {
		ans *= max(0ll, MAX[i] - MIN[i] + 1);
		ans %= Mod;
	}
	cout << ans << endl;
}