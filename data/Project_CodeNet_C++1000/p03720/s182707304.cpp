#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<int>A(N);
	for (int i = 0; i < M; ++i) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		A[x]++;
		A[y]++;
	}
	for (int i = 0; i < N; ++i) {
		cout << A[i] << endl;
	}
}