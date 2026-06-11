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

#define debug(x) cout << #x << " -> " << (x) << endl;
#define debug2(x, y) cout << #x << ' ' << #y << " -> " << (x) << ' ' << (y) << endl;
#define debug3(x, y, z) cout << #x << ' ' << #y << ' ' << #z << " -> " << (x) << ' ' << (y) << ' ' << (z) << endl;
#define debug4(x, y, z, t) cout << #x << ' ' << #y << ' ' << #z << ' ' << #t << " -> " << (x) << ' ' << (y) << ' ' << (z) << ' ' << (t) << endl;
#define debugp(x) cout << #x << " -> " << "(" << (x).F << ", " << (x).S << ")" << endl;
#define debuga(x, n) cout << #x << " -> "; fori (i1_da, n) { cout << (x)[i1_da] << ' '; } cout << endl
#define debugap(x, n) cout << #x << " ->\n"; fori (i1_dap, n) { cout << "(" << (x)[i1_dap].F << ", " << (x)[i1_dap].S << ")\n"; } cout << endl
#define debugaa(x, n, m) cout << #x << " ->\n"; fori (i1_daa, n) { fori (i2_daa, m) { cout << (x)[i1_daa][i2_daa] << ' '; } cout << '\n'; } cout << endl
#define debugav(x, n) cout << #x << " ->\n"; fori (i1_dav, n) { fori (i2_dav, (x)[i1_da].size()) { cout << (x)[i1_dav][i2_dav] << ' '; } cout << '\n'; } cout << endl
#define debugia(x, n) cout << #x << " ->\n"; fori (i1_dia, n) { cout << i1_dia << " : " << (x)[i1_dia] << '\n'; } cout << endl

#define forifrom(i, s, n) for(ll i = (s); i < (n); ++i)
#define forirto(i, n, e) for(ll i = (n) - 1; i >= (e); --i)
#define fori(i, n) forifrom (i, 0, n)
#define forir(i, n) forirto (i, n, 0)

#define smin(a, b) a = min(a, (b))
#define smax(a, b) a = max(a, (b))

#define Add(a, b) a = (a + (b)) % MOD
#define Mul(a, b) a = (a * (b)) % MOD

stringstream sss;

// -----------------------------------------------------------------------

const ll maxn = 300010;

ll n;
pii seq[maxn];
ll ar[maxn];
ll cnt[maxn];

void MAIN() {

    cin >> n;
    memset(ar, -1, sizeof ar);
    fori (i, n) {
        cin >> seq[i].F, seq[i].S = i; --seq[i].F;
        ar[seq[i].F] = i;
    }
    sort(seq, seq + n);
    ll ptr = 0;
    fori (i, n) {
        fori (j, seq[i].S) {
            while (ptr < n*n && ar[ptr] != -1) ++ptr;
            ar[ptr++] = seq[i].S;
        }
    }
    fori (i, n) {
        fori (j, n - seq[i].S - 1) {
            while (ptr < n*n && ar[ptr] != -1) ++ptr;
            ar[ptr++] = seq[i].S;
        }
    }
    ptr = 0;
    fori (i, n) {
        while (ptr <= seq[i].F) {
            cnt[ar[ptr++]]++;
        }
        if (cnt[seq[i].S] != seq[i].S + 1) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
    fori (i, n * n) {
        cout << ar[i] + 1 << ' ';
    }
    cout << '\n';
}

// -----------------------------------------------------------------------

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(10);
    sss << R"(
3
1 5 9
    )";
    MAIN();
    return 0;
}
