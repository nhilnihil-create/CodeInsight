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

//==================================

int main() {
#ifdef FASTIO
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
#endif
#ifdef FILEINPUT
    ifstream ifs("./in_out/input.txt");
    cin.rdbuf(ifs.rdbuf());
#endif

    ll N, X;
    cin >> N >> X;
    Vl A(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }

    ll ans = 0;
    for (ll i = 1; i < N; i++) {
        if (A[i - 1] + A[i] > X) {
            ll r = (A[i - 1] + A[i]) - X;
            if (A[i] >= r) {
                A[i] -= r;
                ans += r;
            }
            else {
                A[i] = 0;
                A[i - 1] = r - A[i];
                ans += r;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}