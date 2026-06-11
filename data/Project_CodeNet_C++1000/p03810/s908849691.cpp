#include "bits/stdc++.h"
using namespace std;

long long GCD(long long X, long long Y) { return (Y == 0 ? X : GCD(Y, X % Y)); }

int main() {
	long long N, COUNT = 0;
	cin >> N;
	vector<long long> V(N);
	for (int i = 0; i < N; i++) cin >> V[i], COUNT += V[i];
	if (N % 2 == 0) {
		cout << (COUNT % 2 == 0 ? "Second" : "First") << endl;
		return 0;
	}
	bool NOW = true;
	long long Odd;
	while (1) {
		COUNT = 0, Odd = 0;
		for (int i = 0; i < N; i++) {
			COUNT += V[i];
			if (V[i] % 2 == 1) Odd++;
		}
		if (COUNT % 2 == 0) {
			cout << (NOW ? "First" : "Second") << endl;
			return 0;
		}
		if (Odd >= 3) {
			cout << (NOW ? "Second" : "First") << endl;
			return 0;
		}
		for (int i = 0; i < N; i++) {
			if (V[i] % 2 == 1) {
				if (V[i] == 1) {
					cout << (NOW ? "Second" : "First") << endl;
					return 0;
				}
				V[i]--;
			}
		}
		long long G = GCD(V[0], V[1]);
		for (int i = 2; i < N; i++) G = GCD(G, V[i]);
		for (int i = 0; i < N; i++) V[i] /= G;
		NOW = !NOW;
	}
}