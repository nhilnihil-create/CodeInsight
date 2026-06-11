//khodaya khodet komak kon
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#pragma GCC optimise ("ofast")
#pragma GCC optimise("unroll-loops")

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 200000 + 10;
const ll MOD = 1000000000 + 7;
const ll INF = 10000000000;
const ll LOG = 25;

ll n, k, h[N], st[N], ft[N], inv[N], par[N][LOG], a[N], ans, Time, lazy[N << 2];
pair<ll, ll> seg[N << 2];
vi G[N];

void DFS(int v = 1, int H = 0, int p = 1){
	st[v] = ++Time;
	inv[Time] = v;
	h[v] = H;
	par[v][0] = p;
	for (int i = 1; i < LOG; i++){
		par[v][i] = par[par[v][i - 1]][i - 1];
	}
	for (auto u:G[v]){
		if (u == p) continue;
		DFS(u, H + 1, v);
	}
	ft[v] = Time;
}

void build(int id, int l, int r){
	if (r - l == 1){
		seg[id] = {0, l};
		return;
	}
	int mid = (l + r) >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid, r);
	return;
}

void modify(int id, ll x){
	seg[id].F += x;
	lazy[id] += x;
}

void shift(int id){
	modify(id << 1, lazy[id]);
	modify(id << 1 | 1, lazy[id]);
	lazy[id] = 0;
}

void add(int id, int lq, int rq, ll x, int l, int r){
	if (rq <= l || r <= lq) return;
	if (lq <= l && r <= rq){
		modify(id, x);
		return;
	}
	shift(id);
	int mid = (l + r) >> 1;
	add(id << 1, lq, rq, x, l, mid);
	add(id << 1 | 1, lq, rq, x, mid, r);
	if (seg[id << 1] > seg[id << 1 | 1]){
		seg[id] = seg[id << 1];
	}else{
		seg[id] = seg[id << 1 | 1];
	}
	return;
}

int walk(int v, int k){
	for (int i = 0; i < LOG; i++){
		if (k & (1 << i)) v = par[v][i];
	}
	return v;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (a[1] != 1) ans ++;
	for (int i = 2; i <= n; i++){
		G[i].pb(a[i]), G[a[i]].pb(i);
	}
	build(1, 1, n + 1);
	DFS();
	//for (int i = 1; i <= n; i++) cout << i << ' ' << h[i] << ' ' << st[i] << ' ' << ft[i] << '\n';
	for (int i = 1; i <= n; i++) add(1, st[i], st[i] + 1, h[i], 1, n + 1);
	
	while (seg[1].F > k){
		ans ++;
		int v = inv[seg[1].S];
		v = walk(v, k - 1);
		add(1, st[v], ft[v] + 1, -INF, 1, n + 1);
	}
	cout << ans;










	return 0;
}
