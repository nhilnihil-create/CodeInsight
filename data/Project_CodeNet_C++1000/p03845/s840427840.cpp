#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> T(N);
	for (int i = 0; i < N; i++) cin >> T[i];

	int M;
	cin >> M;

	vector<int> ans;

	for (int i = 0; i < M; i++) {
		int P, X;
		cin >> P >> X;

		int A = 0;

		for (int j = 0; j < N; j++) {
			if (j == P - 1)A += X;
			else A += T[j];
		}

		ans.push_back(A);
	}

	for (int i = 0; i < M; i++) {
		cout << ans[i] << endl;
	}
}