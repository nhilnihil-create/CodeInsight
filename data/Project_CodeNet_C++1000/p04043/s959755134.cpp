#include <iostream>

using namespace std;

int main(void) {
	int a, b, c;
	int ans = 0;

	cin >> a >> b >> c;

	ans = a + b + c;
	if (ans == 17) {
		cout << "YES" << endl;

	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}