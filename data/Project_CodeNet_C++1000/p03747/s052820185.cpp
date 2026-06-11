#include <bits/stdc++.h>
using namespace std;
#define fori(i, a, b) for(int i = (int) a; i <= (int) b; ++i)
#define rofi(i, b, a) for(int i = (int) b; i >= (int) a; --i)
#define foreach(tt, a) for(auto &tt: a)
#define all(a) begin(a), end(a)
#define csz(a) (int) a.size()
#define pb push_back
#define epb emplace_back
#define mp make_pair
#define load(a, v) fill(begin(a), end(a), v)
#define load_mem(a, v) memset(a, v, sizeof(a));
#define iostream_optimize() ios::sync_with_stdio(false); cin.tie(0);
using ll = long long;
const ll MOD = 1e9+7, LINF = 1e16+1;
const int INF = 1e9+1;
const double EPS = 1e-10;
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
const ll P1 = 31, P2 = 37, M1 = 1e9+7, M2 = 1e9+9;

// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/* <<<<<<<<<<<<<<<<<<<<<<<<<<<< END TEMPLATE >>>>>>>>>>>>>>>>>>>>>>>>>>> */
const int N = 1e5+1;

int n, L, T, x[N], w[N];
int main() {
	iostream_optimize();
	cin >> n >> L >> T;
	ll cnt = 0;
	fori(i, 0, n-1) {
		cin >> x[i] >> w[i];
		if(w[i] == 1) x[i] += T;
		else x[i] -= T;
		cnt += x[i] / L;
		x[i] %= L;
		if(x[i] < 0) {
			--cnt;
			x[i] += L;
		}
	}
	cnt = (cnt % n + n) % n;
	sort(x, x+n);
	fori(i, 0, n-1) cout << x[(i + cnt) % n] << '\n';
}
