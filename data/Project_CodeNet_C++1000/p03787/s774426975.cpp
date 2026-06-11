#include "bits/stdc++.h"
using namespace std;

long long N, M, COUNTX = 0, COUNTY = 0, COUNTZ = 0;
vector<vector<long long> > V;
vector<bool> B;
vector<long long> C;

bool DFS(long long P) {
	B[P] = false;
	bool RET = true;
	for (int NP : V[P]) {
		if (C[NP] == 2) {
			C[NP] = 1 - C[P];
			if (!DFS(NP)) RET = false;
		}
		else {
			if (C[P] == C[NP]) RET = false;
		}
	}
	return RET;
}

int main() {
	cin >> N >> M;
	V.resize(N), B.assign(N, false), C.assign(N, 2);
	for (int i = 0; i < M; i++) {
		long long X, Y;
		cin >> X >> Y;
		X--, Y--;
		V[X].push_back(Y);
		V[Y].push_back(X);
		B[X] = true, B[Y] = true;
	}
	for (int i = 0; i < N; i++) {
		if (!B[i]) COUNTX++;
	}
	for (int i = 0; i < N; i++) {
		if (B[i]) {
			C[i] = 0;
			if (DFS(i)) COUNTY++;
			else COUNTZ++;
		}
	}
	cout << N * N - (N - COUNTX) * (N - COUNTX) + COUNTY * COUNTY + (COUNTY + COUNTZ) * (COUNTY + COUNTZ) << endl;
}