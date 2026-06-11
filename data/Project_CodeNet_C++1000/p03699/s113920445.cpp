#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	vector<int> v(N);
	int sum = 0;

	int m = 100;
	for (int i = 0; i < N; i++) {
		cin >> v.at(i);
		sum += v.at(i);

		if (v.at(i) % 10) {
			if (v.at(i) < m) m = v.at(i);
		}
	}

	if (sum % 10) {
		cout << sum << endl;
	}
	else {
		if (m == 100) cout << 0 << endl;
		else cout << sum - m << endl;
	}
}