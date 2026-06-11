#include <bits/stdc++.h>

using namespace std;

int main() {

	long long n, m;
	cin >> n >> m;

	if (n *2== m) {
		cout << n << endl;
		return 0;
	}

	if (n*2 > m) {
		cout << m / 2 << endl;
	}

	if (n * 2 < m) {
		cout << n+(m/2-n)/2 << endl;
	}

	return 0;

}