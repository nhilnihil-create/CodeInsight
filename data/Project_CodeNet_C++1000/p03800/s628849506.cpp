#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	string S;
	bool X[100000] = {}, check = false;
	cin >> N >> S;
	for (int h = 0; h < 4; h++) {
		if (h % 2 == 0) X[0] = true;
		else X[0] = false;
		if (h < 2) X[1] = true;
		else X[1] = false;
		for (int i = 1; i < N - 1; i++) {
			if (S[i] == 'o') {
				if (X[i]) X[i + 1] = X[i - 1];
				else X[i + 1] = !X[i - 1];
			}
			else {
				if (X[i]) X[i + 1] = !X[i - 1];
				else X[i + 1] = X[i - 1];
			}
		}
		if (S[0] == 'o' && S[N - 1] == 'o') {
			if (X[0] == (X[1] == X[N - 1]) && X[N - 1] == (X[0] == X[N - 2])) {
				check = true;
				break;
			}
		}
		else if (S[0] == 'o' && S[N - 1] == 'x') {
			if (X[0] == (X[1] == X[N - 1]) && X[N - 1] == (X[0] != X[N - 2])) {
				check = true;
				break;
			}
		}
		else if (S[0] == 'x' && S[N - 1] == 'o') {
			if (X[0] == (X[1] != X[N - 1]) && X[N - 1] == (X[0] == X[N - 2])) {
				check = true;
				break;
			}
		}
		else {
			if (X[0] == (X[1] != X[N - 1]) && X[N - 1] == (X[0] != X[N - 2])) {
				check = true;
				break;
			}
		}
	}
	if (check) {
		for (int i = 0; i < N; i++) {
			if (X[i]) cout << 'S';
			else cout << 'W';
		}
	}
	else cout << -1;
}