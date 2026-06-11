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

vector<int> solve(ll n, int alpha) {
	vector<int> res;
	if (n == 0) {
		return res;
	}

	if (n & 1) {
		res.pb(alpha);
		vector<int> add = solve((n - 1) / 2, alpha + 1);
		for (int i = 0; i < add.size() / 2; i++) {
			res.pb(add[i]);
		}
		res.pb(alpha);
		for (int i = add.size() / 2; i < add.size(); i++) {
			res.pb(add[i]);
		}
	}
	else {
		res.pb(alpha);
		vector<int> add = solve((n - 2) / 2, alpha + 2);
		for (int i = 0; i < add.size() / 2; i++) {
			res.pb(add[i]);
		}
		res.pb(alpha + 1);
		res.pb(alpha + 1);
		res.pb(alpha);
		for (int i = add.size() / 2; i < add.size(); i++) {
			res.pb(add[i]);
		}
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	cin >> n;
	vector<int> ans = solve(n, 1);;

	cout << ans.size() << endl;
	for (int i : ans) {
		cout << i << ' ';
	}
	cout << endl;
}

