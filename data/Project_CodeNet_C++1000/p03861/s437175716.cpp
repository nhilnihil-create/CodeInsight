#include "bits/stdc++.h"
using namespace std;

int main() {
	long long a, b, x;
	cin >> a >> b >> x;
	long long s = b / x;
	long long t;
	if (a == 0) {
		t = -1;
	}
	else {
		t = (a - 1) / x;
	}
	cout << s - t << endl;
	return 0;
}