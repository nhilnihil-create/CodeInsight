#include "bits/stdc++.h"
using namespace std;

int main() {
	long long int N, A, sum[200001] = { 0 }, Min = 1000000000000000000;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A;
		sum[i] = sum[i - 1] + A;
	}
	for (int i = 1; i < N; i++) {
		Min = min(Min, abs(sum[N] - 2 * sum[i]));
	}
	cout << Min;
}