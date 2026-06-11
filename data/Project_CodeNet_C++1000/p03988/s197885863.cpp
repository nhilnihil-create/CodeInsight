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

int n, a[maxn], cnt[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		cnt[a[i]]++;
	}
	int MAX = *max_element(a, a + n);
	bool ans = true;
	for (int i = MAX; i >= (MAX + 1) / 2; i--)
	{
		if (i == (MAX + 1) / 2)
		{
			if (MAX & 1)
			{
				if (cnt[i] != 2)
				{
					ans = false;
				}
			}
			else
			{
				if (cnt[i] != 1)
				{
					ans = false;
				}
			}
		}
		else
		{
			if (cnt[i] < 2)
			{
				ans = false;
			}
		}
	}
	for (int i = 0; i < (MAX + 1) / 2; i++)
		if (cnt[i])
			ans = false;

	cout << (ans ? "Possible" : "Impossible") << endl;
}

