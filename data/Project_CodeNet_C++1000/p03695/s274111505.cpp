#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	vector<int> v(9);
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;

		if (n < 3200) v.at(n / 400)++;
		else v.at(8)++;
	}

	int sum = 0;
	for (int i = 0; i < 8; i++) {
		if (v.at(i)) sum++;
	}

	if (v.at(8)) {
		if (!sum) cout << 1 << ' ';
		else cout << sum << ' ';
		cout << sum + v.at(8) << endl;
	}
	else {
		cout << sum << ' ' << sum << endl;
	}
}