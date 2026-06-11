#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int x, a, b;
	cin >> x >> a >> b;

	int A, B;
	A = abs(a - x);
	B = abs(b - x);

	if (A <= B) {
		cout << "A" << endl;
	}
	else {
		cout << "B" << endl;
	}
}