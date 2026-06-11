#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long int64;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const int INF = 1<<29;
const long long  INFL = 1e18;
const int MOD = 1000000007;
const int MAX = 210000;
const int MAX_NUM = 999999999;
void solve() {
	int n; cin >> n;
	int b1, b2, b4;
	b1 = b2 = b4 = 0;
	for (int i = 0; i < n; ++i) {
		int a; cin  >> a;
		if (a % 4  == 0) {
			b4++;
		} else if(a % 2 == 0) {
			b2++;
		} else {
			b1++;
		}
	}
	if (b2 > 0) {
		if (b1 <= b4) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	} else {
		if (b1 <= (b4 + 1)) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	return;
}
int main() {
	solve();
	return 0;
}