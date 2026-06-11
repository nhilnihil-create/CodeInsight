#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int h, w; cin >> h >> w;
	vector<string> s(h);
	vector<int> cnt(26, 0);
	for (int i = 0; i < h; i++) {
		cin >> s[i];
		for (int j = 0; j < w; j++) {
			cnt[s[i][j] - 'a']++;
		}
	}
	if (h & 1) swap(h, w);
	int oc = 0, fc = 0;
	for (int i = 0; i < 26; i++) {
		if (cnt[i] & 1) oc++;
		fc += (cnt[i] >> 2);
	}
	bool ok = false;
	if (h & 1) {
		if (oc == 1) ok = true;
	} else {
		if (w & 1) {
			if (oc == 0) ok = true;
		} else {
			ok = true;
			for (int i = 0; i < 26; i++) if (cnt[i] & 3) ok = false;
		}
	}
	if (fc < (h >> 1) * (w >> 1)) ok = false;
	if (ok) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}
