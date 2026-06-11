#include <iostream>

using namespace std;

int main()
{
	int a[] = { 1,3,5,7,8,10,12 };
	int b[] = { 4,6,9,11 };
	int c[] = { 2 };

	int x, y;
	cin >> x >> y;

	for (int i = 0; i < 7; i++) {
		if (a[i] == x) {
			x = -1;
		}
		if (a[i] == y) {
			y = -1;
		}
	}
	for (int i = 0; i < 4; i++) {
		if (b[i] == x) {
			x = -2;
		}
		if (b[i] == y) {
			y = -2;
		}
	}
	for (int i = 0; i < 1; i++) {
		if (c[i] == x) {
			x = -3;
		}
		if (c[i] == y) {
			y = -3;
		}
	}

	if (x == y) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}