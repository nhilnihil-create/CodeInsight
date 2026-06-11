#include <bits/stdc++.h>
using namespace std;

#define REP(i, m, n) for (int i = (m); i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define rrep(i, x) for (int i = ((int)(x)-1); i >= 0; i--)
#define reps(i, n) for (int i = 0; i <= (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
typedef long long ll;
const int inf = INT_MAX;
const ll INF = 1LL << 60;
const ll mod = 1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    vector<ll> T(N), A(N);
    rep(i, N) cin >> T[i];
    rep(i, N) cin >> A[i];
    ll ans = 1;
    if (N == 1 && T[0] != A[0]) {
        cout << 0 << endl;
        return 0;
    }
    REP(i, 1, N) {
        if (T[i-1] < T[i]) {
            if (T[i] > A[i]) {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    for (int i = N-1; i > 0; i--) {
        if (A[i] < A[i-1]) {
            if (A[i] > T[i]) {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    REP(i, 1, N-1) {
        if (T[i-1] < T[i] || A[i+1] < A[i]) {
            continue;
        } else {
            ans = ans * min(T[i], A[i]);
            ans %= mod;
        }
    }
    cout << ans << endl;
    return 0;
}