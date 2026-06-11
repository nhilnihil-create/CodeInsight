#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mod 1000000007ll
const ll maxn = 9e18;
using namespace std;

void solve() {
	int n, x;
	cin >> n >> x;
	vector<ll> v(n);
	for(int i = 0; i < n; ++i) cin >> v[i];
	ll ans = 0;
	for(int i = 0; i < n - 1; ++i) {
		if(v[i] + v[i + 1] > x) {
			ans += v[i] + v[i + 1] - x;
			if(v[i + 1] >= (v[i] + v[i + 1] - x)) v[i + 1] -= (v[i] + v[i + 1] - x);
			else v[i + 1] = 0;
			}
		}
		cout << ans << endl;
}

int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(35);
	solve();
	return 0;
	}
