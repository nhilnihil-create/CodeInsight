#include "bits/stdc++.h"
using namespace std;

int main() {
	int A, B, C, D, E, F;
	cin >> A >> B >> C >> D >> E >> F;
	vector<bool>W(F + 1, false);
	vector<bool>S(F + 1, false);
	for (int i = 0; i <= F / (100 * A); ++i) {
		for (int j = 0; j <= F / (100 * B); ++j) {
			if ((i * 100 * A + j * 100 * B) <= F) {
				W[i * 100 * A + j * 100 * B] = true;
			}
		}
	}
	for (int i = 0; i <= F / C; ++i) {
		for (int j = 0; j <= F / D; ++j) {
			if ((i*C + j * D) <= F) {
				S[i*C + j * D] = true;
			}
		}
	}
	pair<int, int>ans = make_pair(100, 0);
	for (int i = 0; i <= F; ++i) {
		for (int j = 0; j <= F; ++j) {
			if ((W[i] && S[j]) && (i + j <= F)) {
				if ((j * 100) <= (i*E)) {
					if ((j*ans.first) >= (i*ans.second)) {
						ans = make_pair(i, j);
					}
				}
			}
		}
	}
	cout << ans.first + ans.second << " " << ans.second << endl;
	return 0;
}