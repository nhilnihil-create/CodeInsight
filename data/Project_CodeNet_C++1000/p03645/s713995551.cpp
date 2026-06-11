# include <bits/stdc++.h>
# define rep(i, n) for (ll i = 0; i < (n); i++)
# define reps(i, n) for (ll i = 1; i <= (n); i++)
# define foreps(i, m, n) for (ll i = (m); i < (n); i++)
# define len(x) ((int)(x).size())
# define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
const long long mod = 1e9 + 7;
const long long inf = 1e18;

int main() {
    ll N, M; cin >> N >> M;
    vector<bool> A(200050, false), B(200050, false);
    rep(i, M) {
        ll a, b; cin >> a >> b;
        if (a == 1) A[b] = true;
        if (b == N) B[a] = true;
    }

    rep(i, 200050) {
        if (A[i] && B[i]) {
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}