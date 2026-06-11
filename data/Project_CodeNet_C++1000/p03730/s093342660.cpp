#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int A, B, C;
	cin >> A >> B >> C;


	bool b = false;
	for (int i = 1; i <= A * B; i++) {
		int n = A * i;
		if (n % B == C) {
			b = true;
			break;
		}
	}

	cout << (b ? "YES" : "NO") << endl;
}