#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define all(v) v.begin(),v.end()

const int maxn = 3e5 + 100;
const ll inf = 2e18, mod = 1e9 + 7;

int n;
ll a[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < 3 * n; i++) {
		cin >> a[i];
	}
	sort(a, a + 3 * n);

	ll ans = 0;
	int l = 0, r = 3 * n;
	while (r > l) {
		ans += a[r - 2];
		r -= 2;
		l++;
	}
	cout << ans << endl;
}

