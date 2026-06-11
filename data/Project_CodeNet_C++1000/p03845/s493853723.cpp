#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, T, M, P, X;
	cin >> N;
	vector<int> vec(N);
	int total = 0;
	for (int i = 0; i < N; i++) {
		cin >> T;
		vec.at(i) = T;
		total += T;
	}
	cin >> M;
	vector<int> result(M);
	for (int j = 0; j < M; j++) {
		cin >> P >> X;
		result.at(j) = total + X - vec.at(P - 1);
	}
	for (int k = 0; k < M; k++) {
		cout << result.at(k) << endl;
	}
}
