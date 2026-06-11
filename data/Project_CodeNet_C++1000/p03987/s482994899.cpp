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
//	freopen("water.in", "r", stdin);
//	freopen("water.out", "w", stdout);
 
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
#define rep(i, x, n) for(int i = x; i < n; i++)
#define rrep(i, x, n) for(int i = n - 1; i >= x; i--)
 
#ifdef artem
    #define debug(x) x
    #define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
    #define debug(x)
#endif

void solve() {
	int n;
	cin >> n;
	vector<ll> a(n + 1);
	vector<int> where(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[ i ];
		where[ a[ i ] ] = i;
	}

	set<ll> pos;
	pos.in(0), pos.in(n + 1);
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		int x = where[ i ];
		auto l = *(--pos.lower_bound(x)), r = *pos.lower_bound(x);
		ans += i * (x - l) * (r - x);
		// cout << l << ' ' << r << endl;
		pos.in(x);
	}
	cout << ans << '\n';
}