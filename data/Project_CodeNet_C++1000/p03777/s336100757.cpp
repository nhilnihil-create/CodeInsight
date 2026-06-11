#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	char a, b;
	cin >> a >> b;

	char ans = 'N';
	if (a == 'H') {
		ans = b;
	}
	else {
		if (b == 'H') ans = 'D';
		else ans = 'H';
	}

	cout << ans << endl;
}