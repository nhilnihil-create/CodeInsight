/* In the name of Allah */
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, L, T, x[N], w[N];

void read_input() {
	cin >> n >> L >> T;
	for (int i = 0; i < n; i++)
		cin >> x[i] >> w[i];
}

void solve() {
	int st = 0;
	for (int i = 0; i < n; i++, st = (st % n + n) % n) {
		st += w[i] & 1? L - x[i] > T? 0: (T + x[i]) / L: x[i] < T? (x[i] - L - T + 1) / L: 0;
		x[i] = (1LL * x[i] + (w[i] & 1? T: -T) % L + L) % L;
	}
	sort(x, x + n);
	for (int i = 0; i < n; i++)
		cout << x[(st + i) % n] << endl;
}

int main() {
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	read_input(), solve();
	return 0;
}
