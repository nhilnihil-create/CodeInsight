#include <bits/stdc++.h>
typedef long long ll;
 
using namespace std;

int main() {
	int N, T;
	cin >> N >> T;
	vector<int> a(N);
	vector<int> d;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	vector<int> v(N, 0);
	v[N - 1] = a[N - 1];
	for (int i = N - 2; i > 0; i--) {
		v[i] = max(v[i + 1], a[i]);
	}

	for (int i = 0; i < N - 1; i++) {
		if (v[i + 1] > a[i]) {
			d.push_back(v[i + 1] - a[i]);
		}
	}

	sort(d.begin(), d.end());

	int max_d = d[d.size() - 1];
	auto it = lower_bound(d.begin(), d.end(), max_d);
	int res = d.size() - (it - d.begin());

	cout << res << endl;
	return 0;
}
