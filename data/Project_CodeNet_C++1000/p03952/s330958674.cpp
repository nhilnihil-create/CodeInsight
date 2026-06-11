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

const int maxn = 2e5 + 100;
const ll inf = 2e18, mod = 1e9 + 7;

int n, x, ans[maxn];

int nxt(int val)
{
	if (val == 2 * n - 1)
		return 1;
	return val + 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> x;
	if (x == 2 * n - 1 || x == 1)
		cout << "No" << endl;
	else
	{
		cout << "Yes" << endl;
		ans[n - 1] = x;
		int now = nxt(x);
		for (int i = n; i != n - 1; i = (i + 1) % (2 * n - 1))
			ans[i] = now, now = nxt(now);
		for (int i = 0; i < 2 * n - 1; i++)
			cout << ans[i] << endl;
	}
}

