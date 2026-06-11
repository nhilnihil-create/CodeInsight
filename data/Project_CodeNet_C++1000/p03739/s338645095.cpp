#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N, A[100000], PCount = 0, MCount = 0, sum = 0;
	bool plus = true;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
    //最初のこうが＋
	for (int i = 0; i < N; i++) {
		if (plus) {
			if (sum + A[i] > 0) {
				sum += A[i];
			}
			else {
				PCount += 1 - (sum + A[i]);
				sum = 1;
			}
		}
		else {
			if (sum + A[i] < 0) {
				sum += A[i];
			}
			else {
				PCount += 1 + (sum + A[i]);
				sum = -1;
			}
		}
		plus = !plus;
	}
    //最初のこうがー
	sum = 0, plus = false;
	for (int i = 0; i < N; i++) {
		if (plus) {
			if (sum + A[i] > 0) {
				sum += A[i];
			}
			else {
				MCount += 1 - (sum + A[i]);
				sum = 1;
			}
		}
		else {
			if (sum + A[i] < 0) {
				sum += A[i];
			}
			else {
				MCount += 1 + (sum + A[i]);
				sum = -1;
			}
		}
		plus = !plus;
	}
	cout << min(PCount, MCount);
}
