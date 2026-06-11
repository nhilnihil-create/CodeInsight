#include <iostream>
using namespace std;

int main() {
	int a[4];
	for (int i = 0; i < 4; i++) {
		cin >> a[i];
	}
	int n = 4 / 2;
	int c[n];
	int ans = 0;
	for (int i = 0; i < n; i++) {
		c[i] = a[i * 2] * a[i * 2 + 1];
		if (ans < c[i]) {
			ans = c[i];
		}
	}
	cout << ans << endl;
	return 0;
}