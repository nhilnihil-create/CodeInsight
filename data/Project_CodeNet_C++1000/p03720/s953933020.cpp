#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	vector<int> A(M);
	vector<int> B(M);
	vector<int> rec(N,0);
	for (int i = 0; i < M; i++) {
		cin >> A[i] >> B[i];
	}
	for (int i = 0; i < M; i++) {
		rec[A[i] - 1]++;
		rec[B[i] - 1]++;
	}
	for (int i = 0; i < N; i++) {
		cout << rec[i] << endl;
	}
	return 0;
}