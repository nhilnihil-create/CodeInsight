#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;
using ld = long double;
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
//using oset = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn = 1<<20, mod = (119<<23)+1;
struct node {
	int sum = 0;
	node *l, *r;
	node(int s = 0) : sum(s), l(0), r(0) {}
};
deque<node> buffer;
using pnode = node*;
pnode newnode(int x) {
	buffer.emplace_back(x);
	return &buffer.back();
}
pnode merge(pnode l, pnode r) {
	pnode a = newnode(0);
	a->sum = l->sum + r->sum;
	a->l = l;
	a->r = r;
	return a;
}
pnode init(int l, int r) {
	if(l == r) return newnode(0);
	int mid = (l+r)>>1;
	return merge(init(l, mid), init(mid+1, r));
}
pnode upd(int l, int r, int i, int x, pnode rt) {
	if(l > i || i > r) return rt;
	if(l == r) return newnode(rt->sum + x);
	int mid = (l+r)>>1;
	return merge(upd(l, mid, i, x, rt->l), upd(mid+1, r, i, x, rt->r));
}
int get(int l, int r, int ql, int qr, pnode rt) {
	if(qr < l || r < ql) return 0;
	if(ql <= l && r <= qr) return rt->sum;
	int mid = (l+r)>>1;
	return get(l, mid, ql, qr, rt->l) + get(mid+1, r, ql, qr, rt->r);
}
pnode rt[maxn];
int n, m;
vi h[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int l, r, i = 0; i < n; i++) {
		cin >> l >> r;
		h[l].pb(r);
	}
	for(int i = 0; i <= m; i++) {
		if(i)
			rt[i] = rt[i-1];
		else
			rt[i] = init(0, m);
		for(auto j : h[i]) rt[i] = upd(0, m, j, 1, rt[i]);
		//cout << i << ":\n";
		//for(int j = 0; j <= m; j++) cout << get(0, m, j, j, rt[i]) << ' '; cout << '\n';
	}
	for(int i = 1; i <= m; i++) {
		int ans = 0;
		for(int j = 0; j <= m; j += i) {
			ans += get(0, m, j, min(m, j+i-1), rt[j]);
		}
		cout << ans << '\n';
	}
}
