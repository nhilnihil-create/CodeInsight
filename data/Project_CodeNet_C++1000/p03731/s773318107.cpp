#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int main() {
	ll n, t;
	cin >> n >> t;
	vector<ll> l(n);
	for (int i = 0; i < n; i++)
		cin >> l[i];
	sort(l.begin(), l.end());
	ll head = 0, end = 0;
	ll ans = 0;
	for (int i = 0; i < n - 1; i++) {
		if (l[i] + t < l[i + 1]) {
			end = l[i] + t;
			ans += end - head;
			head = l[i + 1];
		}
	}
	end = l[n - 1] + t;
	ans += end - head;
	cout << ans << endl;
	return 0;
}