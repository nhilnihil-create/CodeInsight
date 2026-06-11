#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define space ' '
typedef long long ll;
typedef long double ld;
const long double PI = 3.14159265358979323846;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

	int n, k, x, y;
	cin >> n >> k >> x >> y;
	ll ans = 0;
	for (int i = 1; i <= k && i <= n; ++i) {
        ans += x;
	}
	for (int i = k + 1; i <= n; ++i) {
        ans += y;
	}
	cout << ans << endl;

    return 0;
}