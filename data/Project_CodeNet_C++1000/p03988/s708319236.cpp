#include <bits/stdc++.h>
using namespace std;

bool solve() {
	int n; cin >> n;
	int cnt[110] = {};
	int maxi = 0;
	for(int i = 0; i < n; ++i) {
		int a; cin >> a;
		cnt[a]++;
		maxi = max(maxi, a);
	}
	if(cnt[maxi] < 2) {
		return false;
	}
	cnt[maxi] -= 2;
	if(maxi % 2 == 0) {
		if(cnt[maxi / 2] < 0) {
			return false;
		}
		--cnt[maxi / 2];
	}
	for(int i = (maxi + 2) / 2; i < maxi; ++i) {
		if(cnt[i] < 2) {
			return false;
		}
		cnt[i] -= 2;
	}	
	for(int i = (maxi + 1) / 2; i > 0; --i) {
		if(cnt[i] > 0) {
			return false;
		}
	}
	return true;
}

int main() {
	cout << (solve() ? "Possible" : "Impossible") << '\n';
	return 0;
}
