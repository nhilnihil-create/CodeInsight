#include <bits/stdc++.h>
#define ll long long
#define rep(i, a, n) for(int i = a; i <= n; i++)
using namespace std;

int n, m;
ll k = 1e9 + 7;

ll f(int n) {
	ll p = 1;
	rep(i, 2, n) p = p * i % k;
	return p;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	if (abs(n - m) > 1) cout << 0;
	else {
		if (n < m) swap(n, m);
		if (n > m) cout << f(n) * f(m) % k;
		else cout << 2 * f(n) * f(n) % k;
	}
}