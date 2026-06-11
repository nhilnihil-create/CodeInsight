#include "bits/stdc++.h"
using namespace std;

int N;
vector<int> A;

bool check(int X) { //答えはX以上か
	vector<bool> B(N * 2 + 1);
	for (int i = 0; i < N * 2 - 1; i++) {
		B[i + 1] = X <= A[i];
	}
	B[0] = B[1], B[N * 2] = B[N * 2 - 1];
	int L = -1, R = -1;
	for (int i = 0; i < N; i++) {
		if (B[N - i] == B[N - i - 1]) return B[N - i];
		if (B[N + i] == B[N + i + 1]) return B[N + i];
	}
}

int main() {
	cin >> N;
	A.resize(N * 2 - 1);
	for (int i = 0; i < N * 2 - 1; i++) cin >> A[i];
	int OK = 1, NG = N * 2;
	while (NG - OK > 1) {
		int MID = (OK + NG) / 2;
		if (check(MID)) OK = MID;
		else NG = MID;
	}
	cout << OK << endl;
}