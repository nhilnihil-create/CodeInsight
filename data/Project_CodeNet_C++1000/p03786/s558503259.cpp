#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<Int> a(N);
	for (int i = 0; i < N; ++i) { cin >> a[i]; }

	sort(a.begin(), a.end());
	Int sum = 0;
	int mx = -1;
	for (int i = 0; i + 1 < N; ++i) {
		sum += a[i];
		if (sum * 2 < a[i + 1]) { mx = i; }
	}
	cout << N - 1 - mx << endl;

	return 0;
}
