#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5010;

int N, K;
int A[MAXN];

bool dppref[MAXN][MAXN], dpsuff[MAXN][MAXN];
int sum[MAXN];

int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	dppref[0][0] = true;
	for (int i = 0; i < N; i++) {
		copy(dppref[i], dppref[i] + K + 1, dppref[i+1]);
		for (int j = 0; j <= K-A[i]; j++) {
			dppref[i+1][j+A[i]] |= dppref[i][j];
		}
	}

	dpsuff[N][0] = true;
	for (int i = N-1; i >= 0; i--) {
		copy(dpsuff[i+1], dpsuff[i+1] + K + 1, dpsuff[i]);
		for (int j = 0; j <= K-A[i]; j++) {
			dpsuff[i][j+A[i]] |= dpsuff[i+1][j];
		}
	}

	// A card is NOT unnecessary <-> a sum in [K-a(i), K-1] can be formed
	int ans = 0;
	for (int i = 0; i < N; i++) {
		int low = K - A[i];
		int high = K - 1;
		for (int j = 0; j <= K; j++) {
			sum[j] = dpsuff[i+1][j];
			if (j > 0) sum[j] += sum[j-1];
		}

		bool found = false;
		for (int j = 0; j <= high; j++) {
			if (!dppref[i][j]) continue;
			int cntOne = sum[high-j];
			if (low-j >= 1) {
				cntOne -= sum[low-j-1];
			}
			found |= bool(cntOne);
		}

		ans += 1 - int(found);
	}

	printf("%d\n", ans);

	return 0;
}
