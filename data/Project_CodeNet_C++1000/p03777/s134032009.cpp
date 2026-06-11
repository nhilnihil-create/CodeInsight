#include <bits/stdc++.h>

using namespace std;

int main() {

	char a, b;

	cin >> a >> b;

	long ans = 0;
	if (a == 'H' && b=='H') {
		ans = 1;
	}
	if (a == 'H' && b == 'D') {
		ans =0;
	}
	if (a == 'D' && b == 'H') {
		ans = 0;
	}
	if (a == 'D' && b == 'D') {
		ans = 1;
	}

	cout << (ans == 1 ? "H" : "D") << endl;
	return 0;

}