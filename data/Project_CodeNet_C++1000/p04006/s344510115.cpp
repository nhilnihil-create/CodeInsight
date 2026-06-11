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
	// freopen("input.txt", "r", stdin);
	// freopen();

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

const int iinf = (int)1e9 + 123123;
const ll linf = (ll)1e17 + 123123;
// const int limit = 10050;
// const int k = 15;
// int st[ limit ][ k ];

// int get_min(int l, int r) {
// 	int j = log2(r - l + 1);
// 	re min(st[ l ][ j ], st[ r - (1 << j) + 1 ][ j ]);
// }

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n + n);
	for(int i = 0; i < n + n; i++) {
		if(i < n) {
			cin >> a[ i ];
		} else {
			a[ i ] = a[ i - n ];
		}
	}

	// for(int i = 0; i < n + n; i++) {
	// 	st[ i ][ 0 ] = a[ i ];
	// }

	// for(int j = 1; j < k; j++) {
	// 	for(int i = 0; i + (1 << j) <= n + n; i++) {
	// 		st[ i ][ j ] = min(st[ i ][ j - 1 ], st[ i + (1 << (j - 1)) ][ j - 1 ]);
	// 	}
	// }

	// ll ans = linf;
	// for(int i = 0; i < n; i++) {
	// 	ll may = x * i;
	// 	for(int j = n - 1; j < n + n - 1; j++) {
	// 		may += get_min(j - i, j);
	// 	}
	// 	ans = min(ans, may);
	// }
	// cout << ans << endl;

	ll ans = linf;
	vector<int> mn(n + n, iinf);
	for(int i = 0; i < n; i++) {
		ll may = x * (ll)i;
		for(int j = n - 1; j < n + n - 1; j++) {
			mn[ j ] = min(mn[ j ], a[ j - i ]);
			// cout << "we have a[ j ] = " << mn[ j ] << endl;
			may += mn[ j ];
		}
		// cout << "look at i = " << i << ", ans = " << may << endl;
		ans = min(ans, may);
	}
	cout << ans << endl;
}