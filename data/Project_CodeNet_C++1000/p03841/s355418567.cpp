#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	pair<int, int> P[500];
	static int ANS[250000] = {};
	int Cur = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int X;
		cin >> X;
		P[i] = { X - 1, i + 1 };
	}
	sort(P, P + N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < P[i].second - 1; j++) {
			while (ANS[Cur] != 0) Cur++;
			ANS[Cur] = P[i].second;
		}
		if (ANS[P[i].first] != 0) {
			cout << "No" << endl;
			return 0;
		}
		ANS[P[i].first] = P[i].second;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - P[i].second; j++) {
			while (ANS[Cur] != 0) Cur++;
			if (Cur < P[i].first) {
				cout << "No" << endl;
				return 0;
			}
			ANS[Cur] = P[i].second;
		}
	}
	cout << "Yes" << endl;
	for (int i = 0; i < N * N; i++) {
		if (i != 0) cout << " ";
		cout << ANS[i];
	}
	cout << endl;
}