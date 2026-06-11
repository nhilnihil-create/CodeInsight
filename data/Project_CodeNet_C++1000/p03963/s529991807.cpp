#include "bits/stdc++.h"

using namespace std;

int main() {
	int N,K;
	cin >> N >>K;
	long long nAns = K;
	for (int n = 1; n <N;++n) {
		nAns *= (K - 1);
	}
	cout << nAns << endl;

	return 0;
}
