#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	int count4 = 0;
	int count2 = 0;
	for (int i = 0; i < N; ++i) {
		int n;
		cin >> n;
		if (0 == n % 4) {
			count4++;
		}
		else if (0 == n % 2) {
			count2++;
		}
	}
	N -= 2 * count4 + 1;
	if (N > 0) {
		N++;
	}
	if (count2 >= N) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}