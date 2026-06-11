#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using ii = pair<int, int>;
 
void solve();
 
clock_t start_time;
double get_current_time() {
	return (double)(clock() - start_time) / CLOCKS_PER_SEC;
}
 
int main() {
	// freopen("substring.in", "r", stdin);
	// freopen("substring.out", "w", stdout);
 
	ios_base::sync_with_stdio(false);
	solve();
}
 
/* ========== actual code starts here ========== */
 
#define fi first
#define re return
#define se second
#define in insert
#define pb push_back
#define eb emplace_back
#define y1 y123123123123
#define all(x) x.begin(), x.end()
#define hash hash123s
 
#define repx(i, x, n) for (int i = x; i < (n); i++)
#define repd(i, n, d) for (int i = 0; i < (n); i += d)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define rrepd(i, n, d) for (int i = (n) - 1; i >= 0; i -= d)
#define rep(i, n) for (int i = 0; i < (n); i++)

template<class t>
void print(t x, int end = 1) {
	cout << x << (end == 1 ? "\n" : " ");
}

template<class T>
void print(const vector<T> &v, int end = 1) {
	rep(i, (int) v.size()) {
		print(v[ i ], 0);
	}
	cout << endl;
}

template<class T>
void print(const set<T> &v, int end = 1) {
	for(auto to = v.begin(); to != v.end(); to++) {
		print(*to);
	}
	cout << endl;
}

template<class T>
void print(const map<T, T> &v, int end = 1) {
	for(auto to : v) {
		print(to.fi, 0);
		cout << ": ";
		print(to.se);
	}
}

template<class t>
void errprint(t x, int end = 1) {
	cerr << x << (end == 1 ? "\n" : " ");
}

#ifdef artem
	#define debug(x) x
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
	#define debug(x)
#endif

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> ans(n), cnt(n, 1);
	ans[ 0 ] = 1;
	rep(i, m) {
		int x, y;
		cin >> x >> y, --x, --y;
		if(ans[ x ]) ans[ y ] = 1;
		cnt[ y ]++;
		cnt[ x ] = max(0, cnt[ x ] - 1);
		if(!cnt[ x ] && ans[ x ]) ans[ x ] = 0;
	}

	int res = 0;
	rep(i, n) if(ans[ i ]) ++res;
	cout << res << endl;
}