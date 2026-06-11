#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	string A, B, C;
	cin >> A >> B >> C;

	char a, b, c, d;
	a = A.at(A.size() - 1);
	b = B.at(0);
	c = B.at(B.size() - 1);
	d = C.at(0);

	if ((a == b) && (c == d)) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}