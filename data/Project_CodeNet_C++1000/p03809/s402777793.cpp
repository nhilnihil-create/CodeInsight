#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
#define rep(x, a, b) for(int x = (a); x <= (b); ++x)
#define rop(x, a, b) for(int x = (a); x < (b); ++x)
#define per(x, a, b) for(int x = (a); x >= (b); --x)
using namespace std;
typedef long long LL;
typedef double DB;
int n, rd[100005], a[100005], x, y, mn[100005];
struct tree {
	int hd[100005], vr[200005], nt[200005], tt;
	void push(int x, int y) {
		vr[++tt] = y; nt[tt] = hd[x]; hd[x] = tt;
	}
	void dfs(int nw, int en) {
		if(nt[hd[nw]] == 0) {mn[nw] = a[nw]; return;}
		int sm, S = 0, T = 0, mx = 0, db = 0, hc = 0;
		for(int i = hd[nw]; i; i = nt[i]) {
			if(vr[i] == en) continue;
			dfs(vr[i], nw);
			if(mx < mn[vr[i]]) S += mx, mx = mn[vr[i]];
			else S += mn[vr[i]];
		}
		
		if(mx > S) {
			T = mx - S;
			sm = mx;
			db = S;
		} else {
			T = (S + mx) & 1;
			sm = (S + mx) / 2 + T;
			db = (S + mx) / 2;
		}
		mn[nw] = T;
		if(sm > a[nw]) {puts("NO"); exit(0);}
		hc = a[nw] - sm;
		if(db < hc) {puts("NO"); exit(0);}
		else mn[nw] += hc * 2;
		return;
	}
}T;
signed main() {
	scanf("%lld", &n);
	rep(i, 1, n) scanf("%lld", &a[i]);
	if(n == 2) {
		if(a[1] == a[2]) puts("YES");
		else puts("NO");
		return 0;
	}
	rop(i, 1, n) {
		scanf("%lld%lld", &x, &y);
		T.push(x, y);
		T.push(y, x);
		rd[x]++;
		rd[y]++; 
	}
	rep(i, 1, n) {
		if(rd[i] > 1) {
			T.dfs(i, 0);
			if(mn[i]) puts("NO");
			else puts("YES");
			return 0;
		}
	}
	return 0;
}
