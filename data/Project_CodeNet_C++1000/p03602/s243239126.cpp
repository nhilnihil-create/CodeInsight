#include <bits/stdc++.h>

using namespace std;

using ll = long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template<typename Q_temp>
using smaller_queue = priority_queue <Q_temp, vector<Q_temp>, greater<Q_temp> >;

const int INF = (int) 1e9;
const ll LINF = (ll) 4e18;
const ll MOD = (ll) (1e9 + 7);
const double PI = acos(-1.0);
const int limit = 100010;

#define REP(i,m,n) for(ll i = m; i < (ll)(n); ++i)
#define rep(i,n) REP(i, 0, n)
#define MP make_pair
#define YES(n) cout << ((n) ? "YES" : "NO") << endl
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << endl
#define NP(v) next_permutation(v.begin(),v.end())
#define debug(x) cout << #x << ":" << x << endl;
#define debug2(x) for(auto a : x) cout << a << " "; cout << endl;
//------------------------------------------------------

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    ll a[n][n];
    bool delete_e[n][n] = {};
    ll ans = 0;

    rep(i, n) rep(j, n) {
        cin >> a[i][j];
        ans += a[i][j];
    }

    rep(i, n) rep(j, n) rep(k, n) {
        if (a[i][j] > a[i][k] + a[k][j]) {
            printf("-1\n");
            return 0;
        } else if (i != k && j != k && a[i][j] == a[i][k] + a[k][j]) {
            delete_e[i][j] = true;
        }
    }

    rep(i, n) rep(j, n) if (delete_e[i][j]) ans -= a[i][j];
    cout << ans / 2 << endl;
    return 0;
}
