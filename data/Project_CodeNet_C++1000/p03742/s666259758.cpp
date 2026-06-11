#include <bits/stdc++.h>
#define int long long
#define range(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) range(i, 0, a)
using namespace std;
const int INF = sizeof(int) == sizeof(long long) ? LLONG_MAX : INT_MAX;
const int MOD = 1000000007;
const long double EPS = 1e-8;

signed main() {
	int x, y;
	cin >> x >> y;
	cout << (abs(x - y) <= 1 ? "Brown" : "Alice") << endl;
	return 0;
}