#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, k;
	cin >> n >> k;

	vector<int> kirai(k);
	for (int i = 0; i < k; i++) {
		cin >> kirai[i];
	}

	for (int i=n; i < n*200; i++) {
		int test = i;
		bool brkflg = false;
		while (1) {
			for (int j = 0; j < k; j++) {
				if (test % 10 == kirai[j]) {
					brkflg = true;
					break;
				}
			}
			if (brkflg) { break; }
			test /= 10;
			if (test == 0) {
				cout << i << endl;
				return 0;
			}

		}
	}

	return 0;

}