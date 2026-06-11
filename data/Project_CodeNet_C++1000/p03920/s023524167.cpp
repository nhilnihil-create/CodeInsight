#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N, COUNT = 0, X;
	vector<long long> ANS;
	cin >> N;
	for (int i = 1; ; i++) {
		ANS.push_back(i);
		COUNT += i;
		if (N <= COUNT) break;
	}
	X = COUNT - N;
	for (int i = 0; i < ANS.size(); i++) if (ANS[i] != X) cout << ANS[i] << endl;
}