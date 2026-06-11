#include <bits/stdc++.h>
#define MAX 200005

using namespace std;

int n, _n, ans = MAX;
int a[MAX], arcrk[MAX], tot;
struct lisan {
	int id, rg;
}tmp[MAX];

inline int Rd() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return x * f;
}
bool cmp(lisan aa, lisan bb) {
	return aa.rg < bb.rg;
}

void init() {
	n = Rd(), _n = n * 2 - 1;
	for(int i = 1; i <= _n; ++i) {
		tmp[i].rg = Rd(), tmp[i].id = i;
	} sort(tmp + 1, tmp + 1 + _n, cmp);
	tmp[0].rg = INT_MAX;
	for(int i = 1; i <= _n; ++i) {
		if(tmp[i].rg != tmp[i - 1].rg) {
			++tot;
			arcrk[tot] = tmp[i].rg;
		}
		a[tmp[i].id] = tot;
	}
//	for(int i = 1; i <= _n; ++i) cout << a[i] << ' ' ; cout << endl;
	return;
}

bool check(int lsk) {
	int lp_0, lp_1, rp_0, rp_1;
	lp_0 = lp_1 = 0, rp_0 = rp_1 = n << 1;
	for(register int i = 1; i < n; ++i) {
		if(a[i] <= lsk && a[i + 1] <= lsk) {
			lp_0 = i;
		} else {
			if(a[i] > lsk && a[i + 1] > lsk) {
				lp_1 = i;
			}
		}
	}
	for(register int i = _n; i > n; --i) {
		if(a[i] <= lsk && a[i - 1] <= lsk) {
			rp_0 = i;
		} else {
			if(a[i] > lsk && a[i - 1] > lsk) {
				rp_1 = i;
			}
		}
	}
	if(lp_0 == 0 && lp_1 == 0 && rp_0 == (n << 1) && rp_1 == (n << 1)) {
		if(n & 1) {
			return a[n] <= lsk;
		} else {
			return a[n] > lsk;
		}
	} else {
		return min(n - lp_0, rp_0 - n) < min(n - lp_1, rp_1 - n);
	}
}
void solve() {
	int l = 1, r = tot, mid;
	while(l <= r) {
		mid = l + r >> 1;
		if(check(mid)) {
			if(ans > mid) ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	return;
}

int main() {
//	freopen("triangle.in", "r", stdin);
//	freopen("triangle.out", "w", stdout);
	init();
	solve();
	cout << arcrk[ans] << endl;
	return 0;
}