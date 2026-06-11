#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
typedef long long lint;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<lint, lint> pll;
typedef unsigned long long ulint;
#define endl '\n'
#define fst first
#define sed second
#define pb push_back
#define mp make_pair
#define rint register int
#define newline putchar('\n')
#define leave_space putchar(' ')
#define all(x) (x).begin(), (x).end()
#define reveal(x) cerr << #x << " = " << (x) << endl
#define rep(it, f, e) for (rint it = (f); it <= (e); ++it)
#define per(it, f, e) for (rint it = (f); it >= (e); --it)
const int MAXN = 1e5 + 10;
const int MAXV = (1 << 18) + 10;
int ary[MAXN];
struct Segment_Tree {
	#define lson (root << 1)
	#define rson (root << 1 | 1)
	#define len(x) (tree[x].stdr - tree[x].stdl + 1)
	#define mid ((tree[root].stdl + tree[root].stdr) >> 1)
	struct Node {
		lint tgl, tgr;
		int stdl, stdr;
	}	tree[MAXV];
	inline void buildtree(int root, int l, int r) {
		tree[root].stdl = l;
		tree[root].stdr = r;
		tree[root].tgl =
		tree[root].tgr = 0;
		if (l == r) return;
		buildtree(lson, l, mid);
		buildtree(rson, mid + 1, r);
	}
	inline void pushdown(int root) {
		if (tree[root].tgr) {
			lint cl = (tree[root].tgr - tree[root].tgl) / (len(root) - 1);
			tree[lson].tgl += tree[root].tgl;
			tree[lson].tgr += tree[root].tgl + (len(lson) - 1) * (cl);
			tree[rson].tgl += tree[root].tgl + len(lson) * cl;
			tree[rson].tgr += tree[root].tgr;
			tree[root].tgl = tree[root].tgr = 0;
		}
	}
	inline void add(int root, int l, int r, int al, int ar) {
		if (l == tree[root].stdl && tree[root].stdr == r) {
			tree[root].tgl += al;
			tree[root].tgr += ar;
			return;
		}
		pushdown(root);
		if (r <= mid) add(lson, l, r, al, ar);
		else if (l > mid) add(rson, l, r, al, ar);
		else {
			add(lson, l, mid, al, al + mid - l);
			add(rson, mid + 1, r, ar - r + mid + 1, ar);
		}
	}
	inline lint getans(int root) {
		if (tree[root].stdl == tree[root].stdr) {
			return tree[root].tgl;
		}
		pushdown(root);
		return max(getans(rson), getans(lson));
	}
	inline void print(int root) {
		if (tree[root].stdl == tree[root].stdr) {
			cout << tree[root].tgl << ' '; return;
		}
		pushdown(root);
		print(lson), print(rson);
	}
	#undef lson
	#undef rson
	#undef mid
	#undef len
}	Tree;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, m;
	lint ans = 0;
	cin >> n >> m;
	Tree.buildtree(1, 1, m); 
	rep (i, 1, n) {
		cin >> ary[i];
	}
	rep (i, 1, n - 1) {
		ans += ary[i] < ary[i + 1] ? ary[i + 1] - ary[i] : ary[i + 1] + m - ary[i];
		if (ary[i] < ary[i + 1]) {
			Tree.add(1, ary[i] + 1, ary[i + 1], 0, ary[i + 1] - ary[i] - 1);
		} else if (ary[i] > ary[i + 1]) {
			if (ary[i] != m) Tree.add(1, ary[i] + 1, m, 0, m - ary[i] - 1);
			Tree.add(1, 1, ary[i + 1], m - ary[i], m - ary[i] + ary[i + 1] - 1);
		}
	}
	cout << ans - Tree.getans(1) << endl;
	return 0;
}