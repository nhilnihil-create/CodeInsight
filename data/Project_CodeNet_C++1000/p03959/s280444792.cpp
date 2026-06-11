#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N, count = 1;
	static long long T[100000], A[100000], MAX[100000], MIN[100000];
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> T[i];
		MAX[i] = T[i];
		if (i == 0) MIN[0] = T[i];
		else if (T[i] != T[i - 1]) MIN[i] = T[i];
		else MIN[i] = 1;
	}
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		MAX[i] = min(MAX[i], A[i]);
	}
	for (int i = 0; i < N - 1; i++) {
		if (A[i] != A[i + 1]) MIN[i] = max(MIN[i], A[i]);
	}
	MIN[N - 1] = max(MIN[N -1], A[N - 1]);
	for (int i = 0; i < N; i++) {
		if (MIN[i] > MAX[i]) {
			count = 0;
			break;
		}
		else count *= MAX[i] - MIN[i] + 1;
		count = count % 1000000007;
	}
	cout << count;
}