#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int X, A, B;
	cin >> X >> A >> B;

	int n = A - B;
	string ans = "N";

	if (n>=0) {
		ans = "delicious";
	}
	else {
		if (abs(n) <= X) ans = "safe";
		else ans = "dangerous";
	}

	cout << ans << endl;
}