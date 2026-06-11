#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	ll ans = 0;
	pair<ll, ll> arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	for (int i = n - 1; i >= 0; i--) {
		if ((arr[i].first + ans )% arr[i].second == 0)
			continue;
		else if (arr[i].first + ans > arr[i].second) {
			ans += (arr[i].second - ((arr[i].first + ans) % arr[i].second));
		} else {
			ans += arr[i].second - (arr[i].first + ans);
		}
		//cout << ans << endl;
	}
	cout << ans << endl;
	return 0;

}
