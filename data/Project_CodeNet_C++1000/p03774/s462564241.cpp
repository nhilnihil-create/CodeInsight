#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>
#include <numeric>


using namespace std;


int main() {
	long long int N, M, tmp, key;
	cin >> N >> M;

	vector<long long int>a(N), b(N), c(M), d(M), ans(N);

	for (int i = 0; i < N; i++) {
		cin >> a[i] >> b[i];
	}

	for (int i = 0; i < M; i++) {
		cin >> c[i] >> d[i];
	}

	for (int i = 0; i < N; i++) {
		key = pow(10, 10);
		for (int j = 0; j < M; j++) {
			tmp = abs(a[i] - c[j]) + abs(b[i] - d[j]);
			if (tmp < key) {
				key = tmp;
				ans[i] = j + 1;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << ans[i] << "\n";
	}

	return 0;
}
