#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using ii = pair<int, int>;
constexpr int MN = 1e5+5;

int main() {
	if (fopen("in", "r")) freopen("in", "r", stdin), freopen("out", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0);

	int N, L, T; cin >> N >> L >> T;

	int p = 0;
	vector<int> v;
	for (int i = 0; i < N; ++i) {
		int x, w; cin >> x >> w;
		if (w == 2) w = -1;
		v.push_back(((x+w*T)%L+L)%L);
		if (w == 1) p = (p+(x+T)/L)%N;
		else p = ((p-(L-x+T-1)/L)%N+N)%N;
	}
	sort(begin(v), end(v));
	for (int i = 0; i < N; ++i) cout << v[(i+p)%N] << '\n';
}
