#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int count_ball[100000];
	for (int i = 0; i < n; ++i)count_ball[i] = 1;
	bool red[100000] = { false };
	red[0] =  true;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		--x; --y;
		if (red[x]) {
			--count_ball[x];
			++count_ball[y];
			red[y] = true;
			if (count_ball[x] == 0) {
				red[x] = false;
			}
		}
		else {
			--count_ball[x];
			++count_ball[y];
		}
	}
	int ans = 0;
	for (bool i : red) {
		ans += i ? 1 : 0;
	}
	cout << ans << endl;

	return 0;
}
