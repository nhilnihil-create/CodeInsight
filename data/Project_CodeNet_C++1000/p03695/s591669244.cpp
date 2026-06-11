#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<int> cnt(9);
	rep(i, n) {
		int t = a[i] / 400;
		if (t > 8) t = 8;
		cnt[t]++;
	}
	int mn = 0;
	rep(i, 8) {
		if (cnt[i]) mn++;
	}
	int mx = mn + cnt[8];
	if (mn == 0) {
		mn++;
	}
	cout << mn << " " << mx << endl;
	return 0;
}