#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)
int main() {
	string s;
	cin >> s;
	vector<ll> a(26);
	for (auto p : s) a[p - 'a']++;
	ll ans = s.size() * (s.size() + 1) / 2;
	rep(i, 26) ans -= a[i] * (a[i] + 1) / 2;
	printf("%lld\n", ans + 1);
	return 0;
}