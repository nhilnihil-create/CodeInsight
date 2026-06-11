#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N, M, A[300][300], Top[300] = {}, COUNT[300] = {}, ANS = 1000;
	bool used[300] = {};
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> A[i][j], A[i][j]--;
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			while (used[A[j][Top[j]]]) Top[j]++;
		}
		for (int j = 0; j < M; j++) COUNT[j] = 0;
		for (int j = 0; j < N; j++) COUNT[A[j][Top[j]]]++;
		long long MAXN = -1, MAXA = -1;
		for (int j = 0; j < M; j++) {
			if (MAXN < COUNT[j]) {
				MAXN = COUNT[j];
				MAXA = j;
			}
		}
		ANS = min(ANS, MAXN);
		used[MAXA] = true;
	}
	cout << ANS << endl;
}