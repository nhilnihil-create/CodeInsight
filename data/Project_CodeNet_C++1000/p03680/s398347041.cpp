#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> A(N);
	for (int i = 0; i < N; i++)cin >> A[i];

	int Q = 1;

	for (int i = 0; i < N; i++) {
		if (A[Q - 1] == 2) {
			cout << i + 1 << endl;
			return 0;
		}
		else Q = A[Q - 1];

		if (i == N - 1) {
			cout << -1 << endl;
			return 0;
		}
	}
}