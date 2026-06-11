#include <bits/stdc++.h>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int mod = (int)1e9 + 7;
const int maxn = 1e5 + 4;
const int inf = (int)1e9;

ll a[10];

int main() {
	ios::sync_with_stdio(false);
	ll ans = 0;
	int n = 7;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ans += (a[0] - (a[0] % 2)) + (a[3] - (a[3] % 2)) + (a[4] - (a[4] % 2)) + a[1];
	ll mn = min (a[0], min (a[3], a[4]));
	if (mn > 0) {
		ll k = (a[0] % 2) + (a[3] % 2) + (a[4] % 2);
		if (k == 2) {
			ans ++;
		}
		if (k == 3) {
			ans += 3;
		}
	}
	cout << ans << endl;
}

