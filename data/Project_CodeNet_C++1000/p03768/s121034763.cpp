#include "bits/stdc++.h"
using namespace std;

struct query {long long V, D, C;};

vector<query> VQ;
vector<vector<long long> > V;
static long long ANS[100000][11] = {};

void DFS(long long v, long long d, long long c) {
	if (ANS[v][d] != 0) return;
	ANS[v][d] = c;
	if (d == 0) return;
	DFS(v, d - 1, c);
	for (long long p : V[v]) DFS(p, d - 1, c);
}

int main() {
	long long N, M, Q;
	cin >> N >> M;
	V.resize(N);
	for (int i = 0; i < M; i++) {
		long long A, B;
		cin >> A >> B;
		A--, B--;
		V[A].push_back(B);
		V[B].push_back(A);
	}
	cin >> Q;
	VQ.resize(Q);
	for (int i = 0; i < Q; i++) {
		cin >> VQ[i].V >> VQ[i].D >> VQ[i].C;
		VQ[i].V--;
	}
	reverse(VQ.begin(), VQ.end());
	for (int i = 0; i < Q; i++) {
		DFS(VQ[i].V, VQ[i].D, VQ[i].C);
	}
	for (int i = 0; i < N; i++) cout << ANS[i][0] << endl;
}