#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 5050, mlg = 17, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
string s, t;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n >> s >> t;
	int ans = 2*n;
	for(int i = 0; i <= s.size(); i++) {
		int ok = 1;
		for(int x = i, y = 0; y < t.size() && x < s.size(); x++, y++) {
			ok &= s[x] == t[y];
		}
		if(ok) ans = min(ans, i+n);
	}
	cout << ans;
}
