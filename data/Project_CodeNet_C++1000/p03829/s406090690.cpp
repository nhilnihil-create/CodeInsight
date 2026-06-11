#include <bits/stdc++.h>
#define REP(i, m, n) for(int (i) = (m); (i) < (n); ++i)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1e9+7;
const ll LINF = 1LL<<60;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> x(n);
    rep(i, n) cin >> x[i];

    ll res = 0;
    rep(i, n - 1) {
        if (a * (x[i + 1] - x[i]) < b) {
            res += a * (x[i + 1] - x[i]);
        }
        else {
            res += b;
        }
    }

    cout << res << endl;

    return 0;
}