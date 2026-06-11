#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; i++) cin >> A[i], A[i]--;
	long long NOW = 0, ANS, MIN = 0;
	for (int i = 0; i < N - 1; i++) {
		if (A[i] > A[i + 1]) NOW += A[i + 1] + 1, MIN++;
		else NOW += A[i + 1] - A[i];
	}
	ANS = NOW;
	vector<pair<int, int> > L(N - 1), R(N - 1);
	for (int i = 0; i < N - 1; i++) {
		L[i] = { A[i], i };
		R[i] = { A[i + 1], i };
	}
	sort(L.begin(), L.end()), sort(R.begin(), R.end());
	int LN = 0, RN = 0;
	for (int i = 0; i < M; i++) {
		NOW -= MIN;
		while (LN < N - 1 && L[LN].first == i) {
			MIN++;
			LN++;
		}
		while (RN < N - 1 && R[RN].first == i) {
			MIN--;
			NOW += (A[R[RN].second + 1] - A[R[RN].second] + M) % M;
			RN++;
		}
		ANS = min(ANS, NOW);
	}
	cout << ANS << endl;
}