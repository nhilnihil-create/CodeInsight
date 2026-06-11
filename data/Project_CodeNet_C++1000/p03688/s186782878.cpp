#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>

using namespace std;

int main() {
	int N, M, m;
	cin >> N;
	int* a = new int[N];

	M = -1; m = 1000000;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		M = max(a[i], M);
		m = min(a[i], m);
	}
	if (M == m) {
		if (M == N - 1 || M * 2 <= N) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	else if (m < M - 1) {
		cout << "No" << endl;
	}
	else {
		int count = 0;
		for (int i = 0; i < N; i++) {
			if (a[i] == m) { count++; }
		}
		if (count + 1 <= M && M <= count + (N - count) / 2) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	return 0;
}