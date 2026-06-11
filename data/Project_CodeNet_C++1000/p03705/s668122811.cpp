#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, a, b;
	cin >> n >> a >> b;
	if (a > b) {
		cout << 0;
		return 0;
	}
	if (a == b) {
		cout << 1;
		return 0;
	}
	if (n == 1) {
		cout << 0;
	} else if (n == 2) {
		cout << 1;
	} else {
		cout << 1LL * (n - 2) * (b - a) + 1;
	}
}