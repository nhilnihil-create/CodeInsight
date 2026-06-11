#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	int N, M;
	cin >> N;

	int total = 0;
	vector<int> T(N);
	for (int i = 0; i < N; ++i) {
		cin >> T[i];
		total += T[i];
	}

	cin >> M;
	for (int i = 0; i < M; ++i) {
		int P, X;
		cin >> P >> X;
		cout << (total + X - T[P-1]) << endl;
	}
	return 0;
}
