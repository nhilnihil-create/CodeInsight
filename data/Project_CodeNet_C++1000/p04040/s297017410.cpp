/*input 
100000 100000 44444 55555
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
const int MX = 200001;
const ld PI = 4*atan((ld)1);

ll fac[MX], ifac[MX];

ll modpow(ll x, ll p) {
	return !p ? 1 : modpow((x * x) % MOD, p / 2) * (p & 1 ? x : 1) % MOD;
}

ll inv(ll x) { return modpow(x, MOD - 2); }

ll binom(ll a, ll b) {
        if (a < b || b < 0 || a < 0) return 0;
        ll tmp = fac[a]*ifac[b] % MOD;
        tmp = tmp*ifac[a-b] % MOD;
        return tmp;
} 

void comp() {
	fac[0] = ifac[0] = 1;
	FOR(i, 1, MX) {
		fac[i] = i * fac[i - 1] % MOD;
		ifac[i] = inv(fac[i]);
	}
}

ll H, W, A, B;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> H >> W >> A >> B;
	comp();

	ll ans = 0;
	ll mx = -1;
	FOR(i, B + 1, W + 1) {
		ll tmp = (binom(H - A + i - 2, H - A - 1) * binom(W + A - i - 1, A - 1));
		ans += tmp;
		ans %= MOD;
	}
	cout << ans << '\n';
}
