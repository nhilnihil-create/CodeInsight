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

void solve() {
    ll N;
    cin >> N;
    Vl A(N + 1);
    for (ll i = 0; i < N; i++) {
        ll a;
        cin >> a;
        A[a] = i + 1;
    }
    set<ll> st;
    st.emplace(0);
    st.emplace(N + 1);
    ll ans = 0;
    for (ll i = 1; i <= N; i++) {
        auto res = st.emplace(A[i]);
        auto itr = res.first;
        ll a, b, c;
        b = *itr;
        --itr;
        a = *itr;
        advance(itr, 2);
        c = *itr;
        ans += i * (b - a) * (c - b);
    }
    cout << ans << "\n";
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