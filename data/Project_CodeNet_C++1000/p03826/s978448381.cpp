#include <bits/stdc++.h>
#define PI 3.14159265359
using namespace std;

int main() {
	int64_t A, B, C, D;
	cin >> A >> B >> C >> D;

	int64_t n, m;
	n = A * B;
	m = C * D;

	if (n > m) {
		cout << n << endl;
	}
	else {
		cout << m << endl;
	}
}