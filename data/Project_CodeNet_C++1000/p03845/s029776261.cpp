#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> T(N);
	for (int i = 0; i < N; i++) {
		cin >> T[i];
	}
	int M;
	cin >> M;
	vector<int> P(M);
	vector<int> X(M);
	for (int i = 0; i < M; i++) {
		cin >> P[i] >> X[i];
	}
	int time = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			time += T[j];
		}
		time = time + X[i] - T[P[i] - 1];
		cout << time << endl;
		time = 0;
	}

	return 0;
}