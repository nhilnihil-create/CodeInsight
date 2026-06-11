#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int A, B, C;
	cin >> A >> B >> C;

	int a, b, c;
	a = A % 3;
	b = B % 3;
	c = (A + B) % 3;

	if (!a || !b || !c) {
		cout << "Possible" << endl;
	}
	else {
		cout << "Impossible" << endl;
	}
}