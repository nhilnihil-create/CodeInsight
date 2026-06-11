/* be name khoda */

// #define stream_enable
#define long_enable
#include <iostream>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <iomanip>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

#ifdef stream_enable
#define cin sss
#endif
#ifdef long_enable
typedef long long int ll;
#else
typedef int ll;
#endif

typedef pair<ll, ll> pii;
typedef pair<pii, ll> ppi;
typedef pair<ll, pii> pip;
typedef vector<ll> vi;
typedef vector<pii> vpii;

const ll MOD = 1000000007;
const long long BIG = 1446803456761533460;
const int Big = 336860180;

#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()

#define debug(x) cout << #x << " -> " << (x) << endl
#define debug2(x, y) cout << #x << ' ' << #y << " -> " << (x) << ' ' << (y) << endl
#define debug3(x, y, z) cout << #x << ' ' << #y << ' ' << #z << " -> " << (x) << ' ' << (y) << ' ' << (z) << endl
#define debug4(x, y, z, t) cout << #x << ' ' << #y << ' ' << #z << ' ' << #t << " -> " << (x) << ' ' << (y) << ' ' << (z) << ' ' << (t) << endl
#define debugp(x) cout << #x << " -> " << "(" << (x).F << ", " << (x).S << ")" << endl
#define debuga(x, n) cout << #x << " -> "; fori (i1_da, n) { cout << (x)[i1_da] << ' '; } cout << endl
#define debugap(x, n) cout << #x << " ->\n"; fori (i1_dap, n) { cout << "(" << (x)[i1_dap].F << ", " << (x)[i1_dap].S << ")\n"; } cout << endl
#define debugaa(x, n, m) cout << #x << " ->\n"; fori (i1_daa, n) { fori (i2_daa, m) { cout << (x)[i1_daa][i2_daa] << ' '; } cout << '\n'; } cout << endl
#define debugav(x, n) cout << #x << " ->\n"; fori (i1_dav, n) { fori (i2_dav, (x)[i1_dav].size()) { cout << (x)[i1_dav][i2_dav] << ' '; } cout << '\n'; } cout << endl
#define debugia(x, n) cout << #x << " ->\n"; fori (i1_dia, n) { cout << i1_dia << " : " << (x)[i1_dia] << '\n'; } cout << endl

#define forifrom(i, s, n) for(ll i = (s); i < (n); ++i)
#define forirto(i, n, e) for(ll i = (n) - 1; i >= (e); --i)
#define fori(i, n) forifrom (i, 0, n)
#define forir(i, n) forirto (i, n, 0)

#define smin(a, b) a = min(a, (b))
#define smax(a, b) a = max(a, (b))

#define Add(a, b) a = ((a) + (b)) % MOD
#define Mul(a, b) a = (1LL * (a) * (b)) % MOD

stringstream sss;

// -----------------------------------------------------------------------

const ll maxn = 2010;

ll n, k;
vi g[maxn];
ll h[maxn];
pii es[maxn];

void dfs(ll x, ll par) {
    for (auto y : g[x]) if (y != par) {
        h[y] = h[x] + 1;
        dfs(y, x);
    }
}

ll count(ll k) {
    ll c = 0;
    fori (i, n) c += h[i] <= k;
    return c;
}

void MAIN() {

    cin >> n >> k;
    fori (i, n - 1) {
        ll a, b; cin >> a >> b; --a, --b;
        g[a].eb(b), g[b].eb(a);
        es[i] = {a, b};
    }
    ll mx = 0;
    if (k % 2) {
        fori (i, n - 1) {
            h[es[i].F] = h[es[i].S] = 0;
            dfs(es[i].F, es[i].S);
            dfs(es[i].S, es[i].F);
            smax(mx, count(k / 2));
        }
    } else {
        fori (i, n) {
            h[i] = 0;
            dfs(i, i);
            smax(mx, count(k / 2));
        }
    }
    cout << n - mx << '\n';

}

// -----------------------------------------------------------------------

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(10);
    sss << R"(
6 2
1 2
3 2
4 2
1 6
5 6
    )";
    MAIN();
    return 0;
}
