#include <bits/stdc++.h>
using namespace std;

using f64 = double;
using i64 = long long;

vector<i64> ariv;

int main() {
#ifdef HOME
	freopen("agc13c.in", "r", stdin);
	freopen("agc13c.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	i64 n, l, t, pos, dir, ord(0);

	cin >> n >> l >> t;
	ariv.resize(n);

	for (int i = 0; i < n; ++i) {
		cin >> pos >> dir;

		pos = pos + ((dir == 1 ? 1 : -1) * t);
		ord+= pos / l;
		pos%= l;
		if (pos < 0) {
			ariv[i] = pos + l;
			--ord; }
		else
			ariv[i] = pos; }

	ord = (ord % n + n) % n;
	sort(begin(ariv), end(ariv));

	for (int i = 0; i < n; ++i)
		cout << ariv[(ord + i) % n] << '\n';

	return 0; }
