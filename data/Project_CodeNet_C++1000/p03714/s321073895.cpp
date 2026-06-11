#include <bits/stdc++.h>
#define N 300001
using namespace std;

typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ul;

ui a[N]; ll l[N], r[N];

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);
#ifdef _DEBUG
	ifstream cin("1.in");
#endif
	ui n; cin >> n;
	for (ui i = 0; i != 3 * n; ++i) cin >> a[i];
	priority_queue<ui, vector<ui>, greater<ui>> ql;
	priority_queue<ui, vector<ui>, less<ui>> qr;
	ul ls = 0;
	for (ui i = 0; i <= 2 * n; ++i) {
		ql.push(a[i]);
		ls += a[i];
		if (ql.size() > n) {
			ls -= ql.top();
			ql.pop();
		}
		l[i] = ls;
	}
	ul rs = 0;
	for (ui i = 3 * n - 1; i >= n; --i) {
		qr.push(a[i]);
		rs += a[i];
		if (qr.size() > n) {
			rs -= qr.top();
			qr.pop();
		}
		r[i] = rs;
	}
	ll ans = 1ll<<63;
	for (ui i = n - 1; i != 2 * n; ++i)
		if(l[i] > r[i]) 
			ans = max(ans, l[i] - r[i + 1]);
	cout << ans << endl;
	return 0;
}