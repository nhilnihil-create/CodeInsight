#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	vector<int> A(N);
	long long totS = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		totS += A[i];
	}
	long long ans = 4e18;
	long long curS = 0;
	for (int i = 0; i+1 < N; i++) {
		curS += A[i];
		ans = min(ans, abs(curS - (totS - curS)));
	}
	cout << ans << '\n';

	return 0;
}
