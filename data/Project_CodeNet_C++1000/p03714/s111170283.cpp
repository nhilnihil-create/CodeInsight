#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using ll = long long;
int main() {
	int n;
	scanf("%d", &n);
	ll a[3 * n];
	rep(i, 3 * n) scanf("%lld", &a[i]);
	vector<ll> l(3 * n), r(3 * n);
	ll now = 0;
	priority_queue<ll, vector<ll>, greater<ll>> que;
	rep(i, n) {
		now += a[i];
		que.push(a[i]);
	}
	l[n - 1] = now;
	repl(i, n, 2 * n) {
		now += a[i];
		que.push(a[i]);
		now -= que.top();
		que.pop();
		l[i] = now;
	}
	priority_queue<ll> q;
	now = 0;
	for (int i = 3 * n - 1; i >= 2 * n; i--) {
		now += a[i];
		q.push(a[i]);
	}
	r[2 * n] = now;
	for (int i = 2 * n - 1; i >= n; i--) {
		now += a[i];
		q.push(a[i]);
		now -= q.top();
		q.pop();
		r[i] = now;
	}
	ll ans = -1e18;
	repl(i, n - 1, 2 * n) ans = max(ans, l[i] - r[i + 1]);
	printf("%lld\n", ans);
	return 0;
}
