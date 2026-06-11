#include <iostream>
#include <string>

using namespace std;

int main()
{
	int x, y;
	cin >> x >> y;

	if (x > 0) {
		if (y > 0) {
			if (y - x >= 0) {
				cout << y - x << endl;
			} else {
				cout << x - y + 2 << endl;
			}
		} else if (y < 0) {
			if (x >= -y) {
				cout << y + x + 1 << endl;
			} else {
				cout << -y - x + 1 << endl;
			}
		} else {
			cout << x + 1 << endl;
		}
	} else if (x < 0) {
		if (y > 0) {
			if (-x >= y) {
				cout << -x - y + 1 << endl;
			} else {
				cout << y + x + 1 << endl;
			}
		} else if (y < 0) {
			if (y - x >= 0) {
				cout << y - x << endl;
			} else {
				cout << -y + x + 2 << endl;
			}
		} else {
			cout << -x << endl;
		}
	} else {
		if (y >= 0) {
			cout << y - x << endl;
		} else {
			cout << -y + 1 << endl;
		}
	}

	return 0;
}