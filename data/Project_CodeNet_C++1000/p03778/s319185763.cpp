#include <bits/stdc++.h>

using namespace std;

int main() {

	long w,a,b;

	cin >> w >> a >> b;

	if (a + w < b) {
		cout << abs(b - a - w) << endl;
	}
	if (a + w >= b && b + w >= a) {
		cout << 0 << endl;
	}
	if (b + w < a) {
		cout << abs(a - b - w) << endl;
	}

	return 0;

}