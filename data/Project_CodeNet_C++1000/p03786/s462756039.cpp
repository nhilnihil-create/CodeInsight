#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ull unsigned long long
#define db long double
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vl;
 
const int N = 1e5 + 123;
const ll inf = 1e18;
ll n, a[N];
ll p[N];
 
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		p[i] = p[i - 1] + a[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ll have = a[i], cur = a[i];
		while (true) {
			int pos = upper_bound(a + 1, a + n + 1, 2 * cur) - a - 1;
			ll s = p[pos] - have;
			if (s == 0) {
				break;
			}
			cur += s;
			have = p[pos];
		}
		if (cur == p[n]) {
			ans++;
		}
	}
	cout << ans;
}
