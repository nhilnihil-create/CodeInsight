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

int n, p[maxn], q[maxn];
ll ans;
set<int> st;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
		q[p[i]] = i;
	}
	st.insert(-1);
	st.insert(n);

	for (int i = 1; i <= n; i++)
	{
		auto it = st.upper_bound(q[i]);
		int r = *it;
		it--;
		int l = *it;
		
		ans += (ll)i * (r - q[i]) * (q[i] - l);
		st.insert(q[i]);
	}
	cout << ans << endl;
}

