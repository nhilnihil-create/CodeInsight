#include <bits/stdc++.h>

using namespace std;

void hawawa()
{
	int n, t;
	int mn = -1;
	long long mx = 0;
	int cnt = 0, cnt2 = 0, mncnt = 0, mxcnt = 0;
	cin >> n >> t;
	t /= 2;
	vector<int> a(n);
	int ans = 0;
	for (auto&& i : a) {
		cin >> i;
		if (mn == -1) mn = i;
		if (mn == i) {
			mncnt++;
		} else if (mn > i) {
			ans += min(mncnt, mxcnt);
			mncnt = 1;
			mxcnt = 0;
			mn = i;
		}
		i -= mn;
		if (mx < i) {
			mxcnt = 1;
			mx = i;
			ans = 0;
		}
		else if (mx == i) {
			mxcnt++;
		}
	}
	ans += min(mncnt, mxcnt);
	cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	hawawa();
	return 0;
}
