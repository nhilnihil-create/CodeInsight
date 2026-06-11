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

static const int mod = 1e9 + 7;

ll powmod(ll a, ll b, ll m) {
    if (b == 0) return 1;
    if (b % 2 == 0) {
        ll t = powmod(a, b / 2, m);
        return t * t % mod;
    }
    else {
        return a * powmod(a, b - 1, m);
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    vector<int> a(n, 0);
    rep(i, n) {
        int b;
        cin >> b;
        a[b]++;
    }

    bool ok = true;
    if (n % 2 == 0) {
        rep(i, n) {
            if (i % 2 == 0 && a[i] > 0) ok = false;
            else if (i % 2 == 1 && a[i] != 2) ok = false;
        }
        if (ok) cout << powmod(2, n / 2, mod) << endl;
    }
    else {
        rep(i, n) {
            if (i == 0 && a[i] != 1) ok = false;
            else if (i % 2 == 1 && a[i] > 0) ok = false;
            else if (i % 2 == 0 && i != 0 && a[i] != 2) ok = false;
        }
        if (ok) cout << powmod(2, (n - 1) / 2, mod) << endl;
    }

    if (!ok) cout << 0 << endl;

    return 0;
}