#include "bits/stdc++.h"
using namespace std;

int main() {
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	if (C >= B) {
		cout << 0 << endl;
	}
	else {
		cout << max(0,min(B, D) - max(A, C)) << endl;
	}
	return 0;
}