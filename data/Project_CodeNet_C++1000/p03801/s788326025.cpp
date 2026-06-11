#include "bits/stdc++.h"
using namespace std;

int main() {
	static long long N, A[100000], COUNT = 0, ANSX[100000] = {}, ANSY[100000] = {}, ANSZ[100000] = {};
	vector<long long> VX, VY;
	cin >> N;
	VX.push_back(0);
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) {
		if (VX[COUNT] < A[i]) {
			COUNT++;
			VX.push_back(A[i]);
			VY.push_back(i);
		}
	}
	for (int i = 0; i < N; i++) {
		long long P = lower_bound(VX.begin(), VX.end(), A[i]) - VX.begin() - 1;
		ANSX[P] += A[i] - VX[P];
		ANSY[P]++;
	}
	for (int i = COUNT - 1; i > 0; i--) {
		ANSX[i - 1] += ANSY[i] * (VX[i] - VX[i - 1]);
		ANSY[i - 1] += ANSY[i];
	}
	for (int i = 0; i < COUNT; i++) {
		ANSZ[VY[i]] = ANSX[i];
	}
	for (int i = 0; i < N; i++) {
		cout << ANSZ[i] << endl;
	}
}