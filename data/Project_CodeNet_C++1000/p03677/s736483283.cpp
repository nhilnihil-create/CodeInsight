#include <bits/stdc++.h>
using namespace std;
#define int long long
int n = 0, m = 0, ans[200500];

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	int rez = 0, las = 0; cin >> las;
	for(int i = 2; i <= n; i++) {
		int x = 0; cin >> x;
		if(las <= x) {
			rez += x - las;
			if(x - las >= 2) {
				ans[las + 2]--;
				if(x <= m - 1) ans[x + 1] += x - las;
				if(x <= m - 2) ans[x + 2] -= x - las - 1;
			}
		} else {
			rez += x + 1;
			if(las <= m - 2) ans[las + 2]--;
			ans[1]--;
			if(x <= m - 1) ans[x + 1] += x + m - las;
			if(x <= m - 2) ans[x + 2] -= x + m - las - 1;
		}

		las = x;
	}
	for(int i = 1, j = 0; i <= m; i++) {
		j += ans[i];
		rez += j;
		ans[i] = rez; 
	}
	int t = ans[1];
	for(int i = 1; i <= m; i++) t = min(t, ans[i]);
	cout << t << endl;
	return 0;
}