#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> A(M);
	for (int i = 0; i < M; i++) cin >> A[i];
	if (M == 1) {
		if (A[0] == 1) cout << 1 << endl << 1 << endl << 1 << endl;
		else cout << A[0] << endl << 2 << endl << A[0] - 1 << ' ' << 1 << endl;
		return 0;
	}
	int Odd = 0;
	for (int i = 0; i < M; i++) {
		if (A[i] % 2 == 1) {
			Odd++;
		}
	}
	if (Odd >= 3) {
		cout << "Impossible" << endl;
		return 0;
	}
	if (Odd == 2) {
		for (int i = 0; i < M; i++) {
			if (A[i] % 2 == 1) {
				swap(A[0], A[i]);
				break;
			}
		}
		for (int i = M - 1; i >= 0; i--) {
			if (A[i] % 2 == 1) {
				swap(A[M - 1], A[i]);
				break;
			}
		}
	}
	if (Odd == 1) {
		for (int i = 0; i < M; i++) {
			if (A[i] % 2 == 1) {
				swap(A[0], A[i]);
				break;
			}
		}
	}
	vector<int> ANS;
	ANS.push_back(A[0] + 1);
	for (int i = 1; i < M - 1; i++) ANS.push_back(A[i]);
	if (A[M - 1] != 1) ANS.push_back(A[M - 1] - 1);
	for (int i = 0; i < M; i++) cout << A[i] << (i == M - 1 ? '\n' : ' ');
	cout << ANS.size() << '\n';
	for (int i = 0; i < ANS.size(); i++) cout << ANS[i] << (i == ANS.size() - 1 ? '\n' : ' ');
}