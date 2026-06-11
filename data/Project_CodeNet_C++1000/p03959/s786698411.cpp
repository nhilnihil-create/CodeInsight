#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define FOR(i, m, n) for (int i = (m); i < (n); i++)
#define FORR(i, m, n) for (int i = (m); i >= (n); i--)
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) FORR(i, n - 1, 0)
#define REP1(i, n) FOR(i, 1, (n) + 1)
#define ALL(c) (c).begin(), (c).end()
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
const int MOD = 1000000007;
const int INF = 1000000001;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);
    vector<int> ac(n, 0);
    vector<int> bc(n, 0);
    REP(i, n) {
        cin >> a[i];
        if (i == 0 || a[i - 1] < a[i]) ac[i] = a[i];
    }
    REP(i, n) cin >> b[i];
    REPR(i, n) {
        if (i == n - 1 || b[i + 1] < b[i]) bc[i] = b[i];
    }

    ll ans = 1;
    REP(i, n) {
        if (ac[i] != 0 && bc[i] != 0) {
            if (ac[i] != bc[i]) {
                cout << 0 << endl;
                return 0;
            }
        } else if (ac[i] != 0 && bc[i] == 0) {
            if (ac[i] > b[i]) {
                cout << 0 << endl;
                return 0;
            }
        } else if (ac[i] == 0 && bc[i] != 0) {
            if (a[i] < bc[i]) {
                cout << 0 << endl;
                return 0;
            }
        } else if (ac[i] == 0 && bc[i] == 0) {
            ans *= (ll)min(a[i - 1], b[i + 1]);
            ans %= MOD;
        }
    }

    cout << ans << endl;
}
