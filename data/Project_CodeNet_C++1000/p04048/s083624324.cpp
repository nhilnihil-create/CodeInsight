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

const int maxn = 1e5 + 100;
const ll inf = 2e18, mod = 1e9 + 7;

ll n, x, ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> x;
	ans = n;
	ll mn = x, mx = n - x;
	if (mn > mx)
		swap(mn, mx);
	while (mn)
	{
		ans += mn * 2 * (mx / mn);
		mx %= mn;
		swap(mn, mx);
	}
	ans -= mx;
	cout << ans << endl;
}

