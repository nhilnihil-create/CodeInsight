#include <bits/stdc++.h>
#define cina(a, n) for (int i = 0; i < n; ++i){ cin >> a[i]; }
#define ll long long
#define ld long double

using namespace std;

int main () {
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	ll a[n];
	cina(a, n);
	sort(a, a+n, greater<int>());
	vector<ll> v;
	for (int i = 0; i < n - 1; ++i) {
		if (a[i] == a[i+1]) {
			v.push_back(a[i++]);
		}
	}
	if (v.size() >= 2)
		cout << v[0] * v[1];
	else
		cout << 0;
	return 0;
}