#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

const int MAXN = 2000 + 123, MXLN = 15;






ll n, x, a[MAXN], lst[MAXN], ans = LLONG_MAX;


int main() {
	cin >> n >> x;
	for (int i = 0; i < n; i++)
		cin >> a[i], lst[i] = a[i];
	for (int k = 0; k < n; k++) {
		ll jav = 0;
		for (int i = 0; i < n; i++)
			jav += lst[i] = min(lst[i], a[((i - k) + n) % n]);
		ans = min(ans, jav + k * x);
	}
	cout << ans;
	return 0;
}