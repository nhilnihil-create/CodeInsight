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
ll x, a[maxn], b[maxn], ans = inf;
multiset<ll> st;
bool mark[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> x;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int k = 0; k < n; k++)
	{
		memset(mark, false, sizeof(mark));
		for (int i = 0; !mark[i]; i = (i + 1) % n)
		{
			st.insert(a[i]);
			if (st.size() == k + 2)
				st.erase(st.find(a[(i - k - 1 + n) % n]));
			if (st.size() == k + 1)
			{
				mark[i] = true;
				b[i] = *st.begin();
			}
		}
		ll cur = x * k;
		for (int i = 0; i < n; i++)
			cur += b[i];
		ans = min(ans, cur);
	}
	cout << ans << endl;
}

