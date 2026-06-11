#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	ll a, b;
	cin >> a >> b;
	if (a <= b) {
		cout << min(b - a, 1 + abs(abs(b) - abs(a)));
	} else if (a > b) {
		if (abs(a) == abs(b)) {
			cout << 1 << endl;
		} else if (a <= 0 && b <= 0) {
			if (a == 0) {
				cout << abs(b) + 1 << endl;
			} else {
				cout << 1 + abs(abs(b) - abs(a)) + 1 << endl;
			}
		} else if (a <= 0 && b >= 0) {

		} else if (a >= 0 && b <= 0) {
			cout << 1 + abs(abs(b) - abs(a)) << endl;
		} else if (a >= 0 && b >= 0) {
			cout << 1 + abs(abs(b) - abs(a)) + 1 << endl;
		}
	}
	return 0;
}
