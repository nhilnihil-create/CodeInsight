/* be name khoda */

#define long_enable
#include <iostream>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <vector>
#include <fstream>
#include <set>
#include <map>
using namespace std;

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

#define forifrom(i, s, n) for (ll i = s; i < n; ++i)
#define forirto(i, n, e) for (ll i = (n) - 1; i >= e; --i)
#define fori(i, n) forifrom (i, 0, n)
#define forir(i, n) forirto (i, n, 0)

#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define smin(a, b) a = min(a, (b))
#define smax(a, b) a = max(a, (b))

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

const ll MOD = 1000000007;
const ll INF = 2000000000;
const long long BIG = 1446803456761533460LL;

#define Add(a, b) a = ((a) + (b)) % MOD
#define Mul(a, b) a = (1LL * (a) * (b)) % MOD

// -----------------------------------------------------------------------

const ll maxn = 100010;
const ll maxnlg = 20;

ll n, m;
vi g[maxn];
vi lt, rt;
bool vis[maxn];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> n >> m;
    fori (i, m) {
        ll a, b; cin >> a >> b;
        g[a].eb(b), g[b].eb(a);
    }
    rt.eb(1);
    bool flag = true;
    ll x = 1;
    vis[x] = 1;
    while (flag) {
        flag = false;
        for (auto y : g[x]) {
            if (!vis[y]) {
                vis[y] = 1;
                rt.eb(y);
                flag = true;
                x = y;
                break;
            }
        }
    }
    x = 1;
    flag = true;
    while (flag) {
        flag = false;
        for (auto y : g[x]) {
            if (!vis[y]) {
                vis[y] = 1;
                lt.eb(y);
                flag = true;
                x = y;
                break;
            }
        }
    }
    ll sz = lt.size();
    sz += rt.size();
    cout << sz << '\n';
    reverse(all(lt));
    for (auto x : lt) cout << x << ' ';
    for (auto x : rt) cout << x << ' ';

}
