//IOI 2021

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 2 * 1000 + 17;

ll n, x, b[MAXN], a[MAXN], ans = 1e18;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> x;
	for (int i = 0; i < n; i++)
		cin >> a[i], b[i] = a[i];
	for (int k = 0; k <= n; k++) {
		ll res = x * k;
		for (int i = 0; i < n; i++)
			b[i] = min(b[i], a[(i - k + n) % n]), res += b[i];
		ans = min(ans, res);
	}
	cout << ans << endl;
	return 0;
}
