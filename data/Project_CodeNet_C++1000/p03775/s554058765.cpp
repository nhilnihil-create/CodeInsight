#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1000000007;
const double PI = acos(-1);

int main()
{
	ll n;
	cin >> n;
	int ans = INT_MAX;
	for (ll a = 1; a <= sqrt(n); a++) {
		if (n % a == 0) {
			ll b = n / a;
			int f = max(to_string(a).size(), to_string(b).size());
			ans = min(ans, f);
		}
		else continue;
	}
	cout << ans << endl;
}
