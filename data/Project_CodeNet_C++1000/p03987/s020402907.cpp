/* it was worth becoming a chemist */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ld;
typedef unsigned int uni;
typedef unsigned long long unll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<long long, int> pli;
typedef pair<int, long long> pil;
typedef vector<int> vi;
typedef vector<long long> vll;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
#define NAME "puts"
#define F first
#define S second

const ll INF = 1e18;
const int inf = 1e9;
const int mod = 1e9 + 7;
const db EPS = (db) 1e-9;
const db pi = acos(-1.0);
const int MAXN = 2e5 + 5;

int n, a[MAXN], id[MAXN];
ll res;

struct seg {
	int mx;
	int mn;
} t[MAXN * 4];

void build(int v, int tl, int tr) {
	t[v].mx = -inf;
	t[v].mn = inf;
	if (tl == tr) return;
	int tm = (tl + tr) >> 1;
	build(v + v, tl, tm);
	build(v + v + 1, tm + 1, tr);
}

void update(int v, int tl, int tr, int pos) {
	if (tl == tr) {
		t[v].mx = t[v].mn = pos;
		return;
	}
	int tm = (tl + tr) >> 1;
	if (pos >= tl && pos <= tm) update(v + v, tl, tm, pos);
	if (pos >= tm + 1 && pos <= tr) update(v + v + 1, tm + 1, tr, pos);
	t[v].mx = max(t[v + v].mx, t[v + v + 1].mx);
	t[v].mn = min(t[v + v].mn, t[v + v + 1].mn);
}

int get_min(int v, int tl, int tr, int l, int r) {
	if (tl >= l && tr <= r) return t[v].mn;
	if (tl > r || tr < l) return inf;
	int tm = (tl + tr) >> 1;
	return min(get_min(v + v, tl, tm, l, r), get_min(v + v + 1, tm + 1, tr, l, r)); 
}

int get_max(int v, int tl, int tr, int l, int r) {
	if (tl >= l && tr <= r) return t[v].mx;
	if (tl > r || tr < l) return -inf;
	int tm = (tl + tr) >> 1;
	return max(get_max(v + v, tl, tm, l, r), get_max(v + v + 1, tm + 1, tr, l, r));
}

int main() {	
   
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		id[a[i]] = i;
	}

	build(1, 1, n);

	for (int i = 1; i <= n; i++) {
		ll l = (ll)get_max(1, 1, n, 1, id[i]);
		if (l == (ll)-inf) l = 1;
		else l++;
		
		ll r = (ll)get_min(1, 1, n, id[i], n);
		if (r == (ll)inf) r = n;
		else r--;
		
		ll ct = 0;
		if (l == id[i]) ct = r - l + 1;
		else ct = (r - id[i] + 1) * (id[i] - l) + (r - id[i] + 1);
	
		
		res += (ct * (ll)i);
		update(1, 1, n, id[i]);
	}

	cout << res;	
	return 0;
}
