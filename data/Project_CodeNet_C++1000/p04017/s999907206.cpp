/*input 
9
1 3 6 13 15 18 19 29 31
10
1
1 9
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) beg(x), en(x)
#define resz resize

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;
const ld PI = 4*atan((ld)1);

int N, L, Q;
vi x;
vpi q;
vector<vi> jump;
vi suc;

int query(int a, int b) {
	if (a == b) return 0;
	F0Rd(i, sz(jump)) {
		if (jump[i][a] < b) return (1 << i) + query(jump[i][a], b);
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	x.pb(0);
	suc.pb(0);
	FOR(i, 1, N + 1) {
		x.pb(0); cin >> x[i];
		suc.pb(0);
	}
	cin >> L >> Q;
	F0R(i, Q) {
		pi z; cin >> z.f >> z.s;
		if (z.f < z.s) q.pb(z);
		else q.pb({z.s, z.f});
	}

	FOR(i, 1, N + 1) {
		suc[i] = ub(all(x), x[i] + L) - beg(x) - 1;
	}

	jump.pb(vi(sz(x)));

	FOR(i, 1, N + 1) {
		jump[0][i] = suc[i];
	}

	for(int i = 1; (1 << i) <= sz(x); i++) {
		jump.pb(vi(sz(x)));
		F0R(j, sz(jump[i])) {
			if (jump[i - 1][j] >= sz(jump[i - 1])) continue;
			jump[i][j] = jump[i - 1][jump[i - 1][j]];
		}
	}

	/*F0R(i, sz(jump)) {
		F0R(j, sz(jump[i])) cout << jump[i][j] << " ";
		cout << '\n';
	}*/

	F0R(i, sz(q)) {
		cout << query(q[i].f, q[i].s) << '\n';
	}
}
