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

int n, k;
ll a[maxn], ans, sum[maxn], ps[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
	{
		if (i)
			sum[i] = sum[i - 1], ps[i] = ps[i - 1];
		if (a[i] > 0)
			sum[i] += a[i];
		ps[i] += a[i];
	}
	for (int i = 0; i < n - k + 1; i++)
	{
		ans = max(ans, sum[n - 1] - (sum[i + k - 1] - (i ? sum[i - 1] : 0)));
		ans = max(ans, (i ? sum[i - 1] : 0) + ps[i + k - 1] - (i ? ps[i - 1] : 0) + sum[n - 1] - sum[i + k - 1]);
	}
	cout << ans << endl;
}

