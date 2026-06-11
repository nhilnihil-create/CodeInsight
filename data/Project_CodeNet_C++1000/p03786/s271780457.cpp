#include <bits/stdc++.h>
using namespace std;

int main() {
	// cin.tie(0);
	// ios::sync_with_stdio(false);

	int N;
	scanf("%d", &N);

	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	sort(A.begin(), A.end());

	int count = 0;
	long long s = 0;
	for (int i = 0; i < N; i++) {
		if (A[i] <= s * 2) {
			count++;
		} else {
			count = 1;
		}
		s += A[i];
	}

	cout << count;
	return 0;
}