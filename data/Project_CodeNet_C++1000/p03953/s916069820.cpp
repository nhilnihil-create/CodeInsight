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

const int maxn = 1e5 + 100, maxlg = 62;
const ll inf = 2e18, mod = 1e9 + 7;

int n, m, f[maxn], perm[maxn], tmp[maxn];
ll k, x[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> x[i];
	for (int i = 0; i < n - 1; i++)
		f[i] = i, perm[i] = i;

	cin >> m >> k;
	for (int i = 0; i < m; i++)
	{
		int pos;
		cin >> pos;
		pos--;
		swap(f[pos], f[pos - 1]);
	}

	while (k)
	{
		if (k & 1)
			for (int i = 0; i < n - 1; i++)
				perm[i] = f[perm[i]];
		for (int i = 0; i < n - 1; i++)
			tmp[i] = f[f[i]];
		swap(tmp, f);
		k /= 2;
	}
	
	ll ans = x[0];
	for (int i = 0; i < n; i++)
	{
		cout << ans << ".0" << endl;
		ans += x[perm[i] + 1] - x[perm[i]];
	}
}

