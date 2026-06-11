#include <bits/stdc++.h>
#define PI 3.14159265359
using namespace std;

int main() {
	int64_t N, x;
	cin >> N >> x;

	vector<int64_t> v(N);
	int64_t bsum = 0, asum = 0;
	for (int64_t i = 0; i < N; i++) {
		cin >> v.at(i);
		bsum += v.at(i);
	}
	//cout << "bsum:" << bsum << endl;

	for (int64_t i = 0; i < N; i++) {
		if (v.at(i) > x) {
			v.at(i) = x;
		}

		if (i > 0) {
			int64_t n = v.at(i - 1) + v.at(i);
			if (n > x) v.at(i) -= n - x;
		}
	}

	for (int64_t i = 0; i < N; i++) {
		asum += v.at(i);
	}
	//cout << "asum:" << asum << endl;

	cout << bsum - asum << endl;
}