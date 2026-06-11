#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int main()
{
	long long x = 1;
	bool flag = false;
	int size = 1;
	for (int t = 0; t < 11; t++) {
		if (t == 10) {
			flag = true;
			break;
		}
		x *= 10;

		cout << "? " << x << endl;

		char c; cin >> c;
		if (c == 'Y') {
			size++;
		}
		else {
			break;
		}
	}

	long long y = 0;
	if (flag) {
		while (1) {
			y *= 10;
			y += 9;

			cout << "? " << y << endl;

			char c; cin >> c;

			if (c == 'Y') {
				cout << "! " << (y + 1) / 10 << endl;
				return 0;
			}
		}
	}

	long long ans = 0;
	for (int i = 0; i < size-1; i++) {
		ans *= 10;

		int l = 0, r = 10;
		int m;
		while (l < r) {
			m = (l + r) / 2;

			cout << "? " << ans + m << endl;

			char c; cin >> c;
			if (c == 'Y') {
				l = m+1;
			}
			else {
				r = m;
			}
		}

		ans += l-1;
	}

	ans *= 10;

	int l = 0, r = 10;
	int m;
	while (l < r) {
		m = (l + r) / 2;

		cout << "? " << (ans + m)*10 << endl;

		char c; cin >> c;
		if (c == 'N') {
			l = m + 1;
		}
		else {
			r = m;
		}
	}

	ans += l;

	cout << "! " << ans << endl;

	return 0;
}

