#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define all(x) (x).begin(), (x).end()
#define fsp(x) cout << fixed << setprecision(x)
const ll inf = LLONG_MAX;
const long double pi = acos(-1);
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);

	ll h, w;
	cin >> h >> w;
	map<char, ll> mp;
	vector<vector<char>> c(h, vector<char>(w));
	for (ll i = 0; i < h; i++) {
		for (ll j = 0; j < w; j++) {
			cin >> c[i][j];
			mp[c[i][j]]++;
		}
	}

	if (h % 2 == 0 && w % 2 == 0) {
		for (auto i = mp.begin(); i != mp.end(); i++) {
			if ((i -> second) % 4 > 0) {
				No();
				return 0;
			}
		}
		Yes();
	}
	else if (h % 2 == 0 || w % 2 == 0) {
		if (w % 2 == 1) swap(h, w);
		ll lim = w / 2;
		for (auto i = mp.begin(); i != mp.end(); i++) {
			if ((i -> second) % 4 == 0) continue;
			if ((i -> second) % 2 == 0) lim--;
			if ((i -> second) % 2 == 1 || lim < 0) {
				No();
				//cout << (i -> first) << " " << (i -> second) << endl;
				return 0;
			}
		}
		Yes();
	}
	else {
		ll lim1 = h / 2 + w / 2, lim2 = 1;
		for (auto i = mp.begin(); i != mp.end(); i++) {
			if ((i -> second) % 4 == 0) continue;
			if ((i -> second) % 2 == 0) lim1--;
			else lim2--;
			if (lim1 < 0 || lim2 < 0) {
				No();
				return 0;
			}
		}
		Yes();
	}
}
