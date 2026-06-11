#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int k, t;
	cin >> k >> t;
	int a;
	int mx = 0;
	for (int i = 0; i < t; i++) {
		cin >> a;
		mx = max(mx, a);
	}

	if (mx > (k + 1) / 2) {
		if (k % 2 == 1) {
			cout << (mx - (k + 1) / 2) * 2 << endl;
		} else {
			cout << (mx - k / 2 - 1) * 2 + 1 << endl;
		}
	} else {
		cout << 0 << endl;
	}

	return 0;
}