#include <bits/stdc++.h>
#define FASTIO
using namespace std;

using ll = long long;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

constexpr int I_INF = numeric_limits<int>::max();
constexpr ll L_INF = numeric_limits<ll>::max();

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

ll binom(ll n, ll k) {
    ll p = 1, q = 1;
    for (ll i = 0; i < k; i++) {
        p *= n - k + i + 1;
        q *= i + 1;
        ll g = gcd(p, q);
        p /= g;
        q /= g;
    }
    return p / q;
}

void solve() {
    ll N, A, B;
    cin >> N >> A >> B;
    Vl V(N), cum(N + 1);
    for (ll i = 0; i < N; i++) {
        cin >> V[i];
    }
    sort(V.begin(), V.end(), greater<ll>());
    for (ll i = 0; i < N; i++) {
        cum[i + 1] = cum[i] + V[i];
    }
    ll s_mx = -1, k_mx = 1;
    ll val = 0;
    for (ll i = A; i <= B; i++) {
        ll s = cum[i];

        if (i * s_mx > k_mx * s) {
            continue;
        }

        if (i * s_mx < k_mx * s) {
            s_mx = s;
            k_mx = i;
            val = 0;
        }

        ll a = V[i - 1];
        ll cnt1 = 0, cnt2 = 0;
        for (ll j = 0; j < N; j++) {
            if (V[j] == a) {
                if (j < i) {
                    ++cnt1;
                }
                else {
                    ++cnt2;
                }
            }
        }

        val += binom(cnt1 + cnt2, cnt1);
    }

    cout << setprecision(20) << (double)s_mx / k_mx << "\n";
    cout << val << "\n";
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

int main() {
#ifdef FASTIO
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
#endif
#ifdef FILEINPUT
    ifstream ifs("./in_out/input.txt");
    cin.rdbuf(ifs.rdbuf());
#endif
#ifdef FILEOUTPUT
    ofstream ofs("./in_out/output.txt");
    cout.rdbuf(ofs.rdbuf());
#endif
    solve();
    cout << flush;
    return 0;
}