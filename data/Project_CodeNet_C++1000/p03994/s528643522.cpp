#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define all(x) (x).begin(), (x).end()
#define fsp(x) fixed << setprecision(x)
//const ll p = 1e9 + 7;
//const ll p = 998244353;
const ll inf = LLONG_MAX;
const long double pi = acos(-1);
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);

	string s;
	ll k;
	cin >> s >> k;
	ll n = s.size();

	vll cnt(n, 0);
	for (ll i = 0; i < n; i++) {
		if (s[i] != 'a') {
			cnt[i] = 26 - (s[i] - 'a');
		}
	}

	for (ll i = 0; i < n; i++) {
		if (cnt[i] <= k) {
			s[i] = 'a';
			k -= cnt[i];
		}
	}
	k %= 26;
	while (k) {
		if (s[n - 1] == 'z') s[n - 1] = 'a';
		else s[n - 1]++;
		k--;
	}

	cout << s << endl;
}
