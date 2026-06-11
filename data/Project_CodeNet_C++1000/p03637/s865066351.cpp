#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	int o,f;
	o = 0;
	f = 0;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		if (n % 4 == 0) f++;
		if (n % 2) o++;
	}

	if (o > f) {
		if ((o + f == N) && (o - 1 == f)) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	else {
		cout << "Yes" << endl;
		return 0;
	}
	cout << "No" << endl;
}