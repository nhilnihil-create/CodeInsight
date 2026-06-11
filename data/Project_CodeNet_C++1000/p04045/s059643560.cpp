#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	int n, k; cin >> n >> k;
	const int p = 10;
	vector<bool> canUse(p, true);
	for (int i = 0; i < k; i++) {
		int d; cin >> d;
		canUse[d] = false;
	}
	int ans;
	int now = n;
	while (true) {
		string now_s = to_string(now);
		bool ok = true;
		for (int i = 0; i < now_s.size(); i++) {
			for (int j = 0; j < p; j++) {
				if (!canUse[(int)(now_s[i] - '0')]) {
					ok = false;
					break;
				}
			}
		}
		if (ok) {
			ans = now;
			break;
		}
		now++;
	}
	cout << ans << endl;
	return 0;
}