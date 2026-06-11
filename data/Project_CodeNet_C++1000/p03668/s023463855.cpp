#include "bits/stdc++.h"
using namespace std;

long long N;
vector<vector<long long> > V;

long long DFS(long long P, long long Q) {
	long long COUNT = 0;
	for (long long NP : V[P]) {
		if (NP != Q) {
			COUNT ^= DFS(NP, P);
		}
	}
	return COUNT + 1;
}

int main() {
	cin >> N;
	V.resize(N);
	for (int i = 0; i < N - 1; i++) {
		long long X, Y;
		cin >> X >> Y;
		X--, Y--;
		V[X].push_back(Y);
		V[Y].push_back(X);
	}
	long long XOR = 0;
	for (long long P : V[0]) {
		XOR ^= DFS(P, 0);
	}
	cout << (XOR == 0 ? "Bob" : "Alice") << endl;
}