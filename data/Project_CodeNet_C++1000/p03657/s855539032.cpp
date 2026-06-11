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
	int a, b; cin >> a >> b;
	if (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0) {
		cout << "Possible" << endl;
		return;
	}
	cout << "Impossible" << endl;
	return;
}
int main() {
	solve();
	return 0;
}