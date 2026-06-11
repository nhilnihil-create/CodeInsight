#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define pb push_back
#define mk make_pair
const int mod = 1e9 + 7;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int>v(n);
	unordered_map<int, int>m;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		m[v[i]]++;
	}
	bool ok = false;
	for (int i = n - 1; i >= 0; i -= 2) {
		if (!(m[i] == 2 || (m[i] == 1 && i == 0)))ok = true;
	}
	if (ok)cout << "0" << endl;
	else {
		ll ans = 1;
		for (int i = 0; i < n / 2; i++) {
			ans *= 2;
			ans = ans % mod;
		}
		cout << ans << endl;
	}
}
