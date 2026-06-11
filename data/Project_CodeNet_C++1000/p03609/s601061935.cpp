
// A - Sandglass2

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int X, t;
	cin >> X >> t;

	int ans = max(0, X - t);

	cout << ans << endl;

	return 0;
}