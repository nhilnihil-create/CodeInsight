#include "bits/stdc++.h"
using namespace std;

int main() {
	string W;
	cin >> W;
	vector<int>A(26);
	for (int i = 0; i < W.size(); ++i) {
		A[W[i] - 'a']++;
	}
	string ansS = "Yes";
	for (int i = 0; i < 26; ++i) {
		if (1 == A[i] % 2) {
			ansS = "No";
		}
	}
	cout << ansS << endl;
	return 0;
}