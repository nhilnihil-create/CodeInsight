#include "bits/stdc++.h"
using namespace std;

long long N, A[100000];
vector<vector<long long> > V;

long long DFS(long long P, long long Q) {
	if (V[P].size() == 1) return A[P];
	long long SUM = 0;
	for (long long NP : V[P]) {
		if (Q == NP) continue;
		long long X = DFS(NP, P);
		if (X == -1) return -1;
		if (X > A[P]) return -1;
		SUM += X;
	}
	if (SUM > A[P] * 2 || SUM < A[P]) return -1;
	return A[P] * 2 - SUM;
}

int main() {
	cin >> N;
	V.resize(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N - 1; i++) {
		long long S, T;
		cin >> S >> T;
		S--, T--;
		V[S].push_back(T);
		V[T].push_back(S);
	}
	for (int i = 0; i < N; i++) {
		if (V[i].size() == 1) {
			cout << (DFS(V[i][0], i) == A[i] ? "YES" : "NO") << endl;
			return 0;
		}
	}
}