#include <bits/stdc++.h>

using namespace std;

#define intt long long

const int N = 100005;

int n, a[N];

map <int, int> mp;

int main() {

	cin >> n;

	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		mp[a[i]] ++;
	}

	int ans = 0, cnte = 0;

	for (int i = 1; i < N; i ++) {
		if (mp[i] > 0) {
			ans ++;
			if (mp[i] % 2 == 0) cnte ++;
		}
	}

	if (cnte % 2) ans --;

	cout << ans << '\n';
}