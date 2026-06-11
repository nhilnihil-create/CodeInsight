#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;

int a[N];
int c[N];

int n, m;
int check(int lim) {
	vector<int> cnt(2);
	for(int i = 1;i <= m;i ++) {
		c[i] = a[i] >= lim;
		cnt[c[i]] ++;
	}
	int mid = m / 2 + 1, dis0 = 0x3f3f3f3f, dis1 = 0x3f3f3f3f;
	for(int i = mid;i < m;i ++) {
		if(c[i] == c[i + 1]) {
			if(c[i]) dis1 = min(dis1, i - mid);
			else dis0 = min(dis0, i - mid);
		}
	}
	for(int i = mid;i > 1;i --) {
		if(c[i] == c[i - 1]) {
			if(c[i]) dis1 = min(dis1, mid - i);
			else dis0 = min(dis0, mid - i);
		}
	}
	if(dis1 == 0x3f3f3f3f && dis0 == dis1) {
		return cnt[1] >= cnt[0];
	}
	else return dis1 <= dis0;
}

int main() {
	ios::sync_with_stdio(false);
	int maxn = 0;
	cin >> n;
	m = 2 * n - 1;
	for(int i = 1;i <= m;i ++) cin >> a[i], maxn = max(maxn, a[i]);
	int l = 0, r = maxn, mid, ans;
	while(l <= r) {
		mid = l + r >> 1;
		if(check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout << ans << endl;
	return 0;
}