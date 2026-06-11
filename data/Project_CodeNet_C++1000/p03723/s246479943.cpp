#include <algorithm>
#include <cmath>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int main() {
	ll A, B, C;
	cin >> A >> B >> C;

	for (int ans = 0; ans < 10000; ans++) {
		if (A % 2 == 1 || B % 2 == 1 || C % 2 == 1) {
			cout << ans << endl;
			return 0;
		}
		ll aa = A / 2, bb = B / 2, cc = C / 2;
		A = bb + cc;
		B = cc + aa;
		C = aa + bb;
		if (A % 2 == 0 && A == B && A == C) break;
 	}
	cout << -1 << endl;
}