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

int n;
ll a[maxn], val[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	ll sum = 0;
	for (int i = 0; i < n; i++)
		cin >> a[i], sum += a[i];
	if (sum % ((ll)n * (n + 1) / 2))
	{
		cout << "NO" << endl;
		return 0;
	}
	ll k = sum / ((ll)n * (n + 1) / 2);
	for (int i = 0; i < n; i++)
		val[i] = a[(i + 1) % n] - a[i];

	ll cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if ((val[i] - k) % n)
		{
			cout << "NO" << endl;
			return 0;
		}
		cnt += abs(val[i] - k) / n;
	}
	if (cnt != k)
	{
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
}

