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

ll solve(bool b, ll n, ll m) {
    ll res = 1;
    reps(i, n) {
        res = (res * i) % mod;
    }
    reps(i, m) {
        res = (res * i) % mod;
    }
    if (b) return (2 * res) % mod;
    else return res % mod;
}

int main() {
    ll N, M; cin >> N >> M;

    ll absolute = abs(N - M);
    if (2 <= absolute) cout << 0 << endl;
    else if (absolute == 1) cout << solve(false, N, M) << endl;
    else cout << solve(true, N, M) << endl;
}