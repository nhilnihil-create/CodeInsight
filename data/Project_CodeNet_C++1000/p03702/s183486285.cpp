#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define pb push_back
#define mk make_pair
ll n, a, b;
bool solve(ll x, vector<ll>v) {
	ll needed = 0;
	for (int i = 0; i < int(v.size()); i++) {
		ll left = v[i] - b * x;
		if (left < 0)continue;
		needed += (left + (a - b - 1)) / (a - b);
	}
	if (needed > x)return false;
	return true;
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> a >> b;
	vector<ll>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int left = 0, right = 1e9;
	while (right - left > 1) {
		ll mid = (right + left) / 2;
		if (solve(mid, v))
			right = mid;
		else
			left = mid;
	}
	cout << left + 1 << endl;
}