#include <bits/stdc++.h>
using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	for (int i = 0; i < 1000000; i++) {
		if ((A * i - C) % B == 0) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
