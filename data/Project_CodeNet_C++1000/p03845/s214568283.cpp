#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int>T(N);
	int sum = 0;
	for (int i = 0; i < N; ++i) {
		cin >> T[i];
		sum += T[i];
	}
	int M;
	cin >> M;
	for (int i = 0; i < M; ++i) {
		int p, x;
		cin >> p >> x;
		cout << sum - T[p - 1] + x << endl;
	}
	return 0;
}