#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int W, a, b;
	cin >> W >> a >> b;

	int ans = 0;
	if (a + W < b) {
		ans = b - (a + W);
	}
	else if (a > b + W) {
		ans = a - (b + W);
	}

	cout << ans << endl;
}