#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mod 1000000007ll
const ll maxn = 9e18;
using namespace std;

void solve() {
	int k, s;
	ll ans = 0;
	cin >> k >> s;
	for(int x = 0; x <= k; ++x) {
		for(int y = 0; y <= k; ++y) {
			int z = s - x - y;
			if(z >= 0 && z <= k) ans++;
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
