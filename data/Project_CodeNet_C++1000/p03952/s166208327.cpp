#include <bits/stdc++.h>
using namespace std;

//https://atcoder.jp/contests/agc006/tasks/agc006_b

int n, x;

int main() {
	cin >> n >> x;
	if (x == 1 || x == 2 * n - 1) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;

	int a = (n - 1 + x) % (2 * n - 1);
	for (int i = 0; i < 2 * n - 1; ++i)
		cout << (a + i) % (2 * n - 1) + 1 << endl;
}
