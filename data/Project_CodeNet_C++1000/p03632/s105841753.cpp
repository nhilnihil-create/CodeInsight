#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int A, B, C, D;
	cin >> A >> B >> C >> D;

	int n, m;
	n = max(A, C);
	m = min(B, D);

	if (n >= m) cout << 0 << endl;
	else cout << m - n << endl;
}