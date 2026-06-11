#include<bits/stdc++.h>
#define int long long
using namespace std;
// by piano
template<typename tp> inline void read(tp &x) {
    x = 0;char c = getchar();bool f = 0;
    for(; c < '0' || c > '9'; f |= (c == '-'), c = getchar());
    for(; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + c - '0', c = getchar());
    if(f) x = -x;
}
const int N = 3e5 + 10;
int tr[N], n, m, L[N], R[N], st[N], top = 0, sum[N], op[N];

struct P {
	int L, R, len;
}p[N];

inline bool cmp(P a, P b) {
	return a.len < b.len;
}

struct T {
	#define ls (rt << 1)
	#define rs (rt << 1 | 1)
	#define mid ((l) + (((r) - (l)) >> 1))
	int tr[N << 2], tag[N << 2];
	inline void pd(int rt, int l, int r) {
		if(tag[rt]) {
			tr[ls] += tag[rt] * (mid - l + 1);
			tr[rs] += tag[rt] * (r - mid);
			tag[ls] += tag[rt];
			tag[rs] += tag[rt];
			tag[rt] = 0;
		}
	}
	
	inline void A(int L, int R, int C, int l, int r, int rt) {
		if(L <= l && r <= R) {
			tr[rt] += C * (min(r, R) - max(l, L) + 1);
			tag[rt] ++;
			return ;
		}pd(rt, l, r);
		if(L <= mid) A(L, R, C, l, mid, ls);
		if(R > mid) A(L, R, C, mid + 1, r, rs);
		tr[rt] = tr[ls] + tr[rs];
	}
	
	inline int Q(int L, int R, int l, int r, int rt) {
		if(L <= l && r <= R) return tr[rt];
		pd(rt, l, r);
		int ans = 0;
		if(L <= mid) ans += Q(L, R, l, mid, ls);
		if(R > mid) ans += Q(L, R, mid + 1, r, rs);
		return ans;
	}
	
	inline int ADD(int x, int val) {
		for(; x <= n ;x += x & -x) tr[x] += val;
	}
	
	inline int QUE(int x, int ans = 0) {
		for(ans = 0; x >= 1; x -= x & -x) ans += tr[x]; return ans;
	}
	
}s1, s2;


main() {
	read(m), read(n); 
	for(int i = 1; i <= m; i ++) {
		read(p[i].L), read(p[i].R);
		p[i].len = p[i].R - p[i].L + 1;
	}
	sort(p + 1, p + m + 1, cmp);
	int k = 1;
//	for(int i = 1; i <= m; i ++)
//		cout << i << "th " << p[i].L << ' ' << p[i].R << "\n";
	for(int i = 1; i <= n; i ++) {
		for(; k <= m && p[k].len < i; k ++) {
//			s1.A(p[k].L, p[k].R, 1, 1, n, 1);
			s1.ADD(p[k].L, 1);
			s1.ADD(p[k].R + 1, -1);
		}
		int ans = m - k + 1;
		for(int t = i; t <= n; t += i) ans += //s1.Q(t, t, 1, n, 1);//
		s1.QUE(t);
		cout << ans << "\n";
	}
//	for(int i = 1; i <= n; i ++)
//		printf("%lld\n", s2.Q(i, 1, n, 1));
}