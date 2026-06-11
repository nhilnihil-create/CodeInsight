#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	ll a[3 * n];
	ll f[n + 1], s[n + 1];
	f[0] = 0; s[n] = 0;
	
	priority_queue<ll, vector<ll>, greater<ll>> fh;
	priority_queue<ll> sh;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		fh.push(a[i]);
		f[0] += a[i];
	}
	for (int i = n; i < 2 * n; i++) {
		cin >> a[i];
		if (a[i] > fh.top()) {
			f[i - n + 1] = f[i - n] + a[i] - fh.top();
			fh.pop();
			fh.push(a[i]);
		} else f[i - n + 1] = f[i - n];
	}
	for (int i = 2 * n; i < 3 * n; i++) {
		cin >> a[i];
		sh.push(a[i]);
		s[n] += a[i];
	}
	for (int i = 2 * n - 1; i >= n; i--) {
		if (a[i] < sh.top()) {
			s[i - n] = s[i - n + 1] + a[i] - sh.top();
			sh.pop();
			sh.push(a[i]);
		} else s[i - n] = s[i - n + 1];
	}

	ll ans = f[0] - s[0];
	for (int i = 1; i <= n; i++)
		ans = max(ans, f[i] - s[i]);
	cout << ans;
}