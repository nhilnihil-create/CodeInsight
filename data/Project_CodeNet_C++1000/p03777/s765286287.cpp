#include <iostream>
using namespace std;

int main() {
	char a, b;
	cin >> a >> b;
	int a2, b2;
	if (a == 'H') {
		a2 = 1;
	} else {
		a2 = -1;
	}
	if (b == 'H') {
		b2 = 1;
	} else {
		b2 = -1;
	}

	char ans;
	if (a2 * b2 == 1) {
		ans = 'H';
	} else {
		ans = 'D';
	}
	cout << ans << endl;
	return 0;
}