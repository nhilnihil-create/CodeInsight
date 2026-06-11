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

    ll N, K;
    cin >> N >> K;

    Vl A(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }

    ll mx = *max_element(A.begin(), A.end());
    ll g = 0;
    for (ll i = 0; i < N; i++) {
        g = __gcd(g, A[i]);
    }

    bool ok = true;
    if (mx < K) {
        ok = false;
    }

    if (K % g != 0) {
        ok = false;
    }

    cout << (ok ? "POSSIBLE\n" : "IMPOSSIBLE\n");

    return 0;
}