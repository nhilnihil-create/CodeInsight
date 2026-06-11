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

const ll maxn = 100010;

ll n, m, k, cn;
ll X[maxn], A[maxn], T[maxn], P[maxn];
pii pos[maxn];
vi cyc[maxn];

void MAIN() {

    cin >> n;
    fori (i, n) cin >> X[i];

    fori (i, n - 1) T[i] = X[i + 1] - X[i];
    iota(P, P + n - 1, 0);

    cin >> m >> k;
    fori (i, m) cin >> A[i], --A[i];

    fori (i, m) swap(P[A[i]], P[A[i] - 1]);

    fori (i, n - 1) pos[i].F = -1;
    fori (i, n - 1) {
        if (pos[i].F != -1) continue;
        ll x = i;
        ll t = 0;
        do {
            pos[x] = {cn, t++};
            cyc[cn].eb(x);
            x = P[x];
        } while (x != i);
        ++cn;
    }

    fori (i, n) {
        ll a, b; tie(a, b) = pos[i];
        ll csz = cyc[a].size();
        P[i] = cyc[a][(b + k) % csz];
    }

    fori (i, n - 1) {
        cout << X[i] << '\n';
        X[i + 1] = X[i] + T[P[i]];
    }
    cout << X[n - 1] << '\n';

}

// -----------------------------------------------------------------------

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(10);
    sss << R"(
5
0 1 3 6 10
3 10
2 3 4

13
5 2 9 3 1 7 4 4 8 -4 7 9 6
18 20
2 3 4 5 6 7 8 9 10 11 12 6 3 4 7 4 4 5

7 2 3 4 5 6 8 7 9 10 11 12 6 7 3 9 4

8
5 2 9 3 1 7 4 4
6 10
7 2 3 4 5 6 


    )";
    MAIN();
    return 0;
}
