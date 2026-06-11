#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	long long X, Y; cin >> X >> Y;
	if (abs(X-Y) <= 1) {
		cout << "Brown" << '\n';
	} else {
		cout << "Alice" << '\n';
	}

	return 0;
}
