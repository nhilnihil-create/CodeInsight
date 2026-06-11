#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int a, b, c;
	cin >> a >> b >> c;
	if (a == b && b == c) {
		if (a % 2 == 0) {
			cout << -1 << '\n';
			return 0;
		} else {
			cout << 0 << '\n';
			return 0;
		}
	}
	int cnt = 0;
	while (a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
		int tempA = a, tempB = b, tempC = c;
		tempA = (a + b) / 2;
		tempB = (b + c) / 2;
		tempC = (c + a) / 2;
		a = tempA;
		b = tempB;
		c = tempC;
		cnt++;
	}
	cout << cnt << '\n';

	return 0;
}
