#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	unordered_map<ll, ll> mp;
	for (int i = 0; i < n; i++) {
		ll a; cin >> a;
		mp[a]++;
	}
	vector<pair<ll,bool>> c;
	for (auto u : mp) {
		if (4 <= u.second) {
			c.push_back({ u.first,true });
		}
		else if (2 <= u.second) {
			c.push_back({ u.first,false });
		}		
	}
	sort(c.rbegin(), c.rend());
	ll l = -1;
	ll s = -1;
	for (int i = 0; i < c.size(); i++) {
		if (l == -1) {
			if (c[i].second) {
				cout << c[i].first * c[i].first << endl;
				return 0;
			}
			else {
				l = c[i].first;
			}
		}
		else if (s == -1) {
			s = c[i].first;
			break;
		}
	}
	if (c.size() < 2) cout << 0 << endl;
	else cout << l * s << endl;
    return 0;
}