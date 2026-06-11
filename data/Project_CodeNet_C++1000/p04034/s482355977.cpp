#include <bits/stdc++.h>
using namespace std;

#define ferrari ios_base::sync_with_stdio(false); cin.tie(NULL)

const int N = 100100;

int n, m, cnt[N], ans;
bool red[N];

int main() {
	cin >> n >> m;
	red[1] = true;
	fill(cnt + 1, cnt + 1 + n, 1);
	while (m--) {
		int x, y;
		cin >> x >> y;
		if (red[x]) red[y] = true;
		cnt[x]--, cnt[y]++;
		if (cnt[x] == 0) red[x] = false;
	}
	for (int i = 1; i <= n; i++)
		ans += red[i];
	cout << ans;
}
