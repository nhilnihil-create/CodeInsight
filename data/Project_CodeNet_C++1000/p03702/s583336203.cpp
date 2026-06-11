#include <bits/stdc++.h>
#define N 100000
using namespace std;

typedef unsigned long long ui;

ui h[N], n, a, b;

bool chk(ui w) {
	ui s = 0;
	for (ui i = 0; i != n; ++i) {
		if (h[i] > b * w)
			s += (h[i] - 1 - b * w) / (a - b) + 1;
	}
	return s <= w;
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);
#ifdef _DEBUG
	ifstream cin("1.in");
#endif
	cin >> n >> a >> b;
	for (ui i = 0; i != n; ++i) cin >> h[i];
	ui l = 1, r = 1 << 30;
	while (l < r) {
		ui mid = (l + r) >> 1;
		if (chk(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << endl;
	return 0;
}