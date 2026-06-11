#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N;
	cin >> N;
	N++;
	vector<int> V;
	while (N > 0) {
		V.push_back(N % 2);
		N >>= 1;
	}
	vector<int> ANS;
	for (int t = 0; t < 2; t++) {
		for (int i = 0; i < V.size() - 1; i++) ANS.push_back(i);
	}
	int NOW = V.size() - 1;
	for (int i = V.size() - 2; i >= 0; i--) {
		if (V[i] == 1) {
			ANS.push_back(NOW);
			for (int j = 0; j < i; j++) {
				swap(ANS[ANS.size() - 1 - j], ANS[ANS.size() - 2 - j]);
			}
			ANS.push_back(NOW);
			NOW++;
		}
	}
	cout << ANS.size() << endl;
	for (int i = 0; i < ANS.size(); i++) {
		cout << ANS[i] + 1 << (i == ANS.size() - 1 ? '\n' : ' ');
	}
}