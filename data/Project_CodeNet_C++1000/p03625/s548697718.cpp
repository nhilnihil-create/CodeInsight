#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n; cin >> n;
	map<ll, ll> mp;
	for (ll i = 0; i < n; i++) {
		ll a; cin >> a;
		mp[a]++;
	}
	ll squareLength = -1;
	ll rectangleFirst = -1;
	ll rectangleSecond = -1;
	for (auto u : mp) {
		if (4 <= u.second) {
			squareLength = max(squareLength, u.first);
			rectangleSecond = max(rectangleSecond, u.first);
			rectangleFirst = max(rectangleFirst, u.first);
		}
		else if (2 <= u.second) {
			rectangleSecond = rectangleFirst;
			rectangleFirst = max(rectangleFirst, u.first);			
		}
	}
	ll ans;
	if (squareLength == -1) {
		if (rectangleFirst == -1 || rectangleSecond == -1) ans = 0;
		else ans = rectangleFirst * rectangleSecond;
	}
	else {
		if (rectangleFirst == -1 || rectangleSecond == -1) {
			ans = squareLength * squareLength;
		}
		else {
			ans = max(squareLength * squareLength, rectangleFirst * rectangleSecond);
		}
	}
	cout << ans << endl;
	return 0;
}