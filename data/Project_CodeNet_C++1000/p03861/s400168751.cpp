#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mod 1000000007ll
const ll maxn = 9e18;
using namespace std;

void solve() {
	ll a, b , x;
	cin >> a >> b >> x;
	ll t;
	t = a / x;
	ll ans = b / x - t;
	if(a % x == 0) ans++;
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
