#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	bool bl = false;
	if ((b - a) == (c - b)) {
		bl = true;
	}

	cout << (bl ? "YES" : "NO") << endl;
}