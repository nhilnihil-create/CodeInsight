#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	const int p = 8;
	int n; cin >> n;
	vector<int> num(p, 0);
	int free = 0;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		for (int j = 0; j < p; j++) {
			if (400 * j <= a && a < 400 * (j + 1)) {
				num[j] = 1;
			}
		}
		if (400 * p <= a) free++;
	}
	int ans = 0;
	for (int i = 0; i < p; i++) {
		if (1 == num[i]) ans++;
	}
	if(ans == 0) cout << 1 << " " << free << endl;
	else cout << ans << " " << ans + free << endl;
	return 0;
}