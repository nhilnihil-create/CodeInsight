#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

int n;
// Map for parity
map<ll, int> m;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		m[a[i]] = i % 2;
	}
	
	sort(all(a));
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (i % 2 != m[a[i]]) ++cnt;
	}
	
	cout << cnt / 2;
}
