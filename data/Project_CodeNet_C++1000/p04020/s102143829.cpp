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
 
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repx(i, x, n) for (int i = x; i < (n); i++)
#define repd(i, n, d) for (int i = 0; i < (n); i += d)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define rrepd(i, n, d) for (int i = (n) - 1; i >= 0; i -= d)
 
#ifdef artem
	#define debug(x) x
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
	#define debug(x)
#endif
 
void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[ i ];
	}
	ll ans = 0;
	rep(i, n) {
		ans += a[ i ] / 2;
		if(i + 1 < n && a[ i + 1 ] != 0 && a[ i ] % 2 != 0) {
			++ans;
			a[ i ]--;
			a[ i + 1 ]--;
		}
	}
	cout << ans << endl;
}