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
    ll N; cin >> N;
    vector<ll> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    vector<ll> C(N + 1, 0);
    for (ll i = N - 1; i >= 0; i--) {
        A[i] += C[i + 1];
        ll modd = A[i] % B[i];
        ll need = 0;
        if (modd != 0) need = B[i] - modd;
        C[i] = C[i + 1] + need;
    }
    cout << C[0] << endl;
}