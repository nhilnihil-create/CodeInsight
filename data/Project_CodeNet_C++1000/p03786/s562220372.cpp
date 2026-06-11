#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<Int> a(N);
	for (int i = 0; i < N; ++i) { cin >> a[i]; }

	sort(a.begin(), a.end());
	auto check = [&](int mid) {
		Int sum = 0;
		for (int i = 0; i < N; ++i) {
			if (i > mid && sum * 2 < a[i]) { return false; }
			sum += a[i];
		}
		return true;
	};

	int low = -1, high = N - 1;
	while (high - low > 1) {
		int mid = (high + low) / 2;
		(check(mid) ? high : low) = mid;
	}
	cout << N - high << endl;

	return 0;
}
