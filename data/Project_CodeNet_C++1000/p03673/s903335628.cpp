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
    Vl A(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }

    deque<ll> b;
    bool is_rev = false;

    for (ll i = 0; i < N; i++) {
        if (is_rev) {
            b.emplace_front(A[i]);
        }
        else {
            b.emplace_back(A[i]);
        }
        is_rev ^= true;
    }

    if (is_rev) {
        for (ll i = N - 1; i >= 0; i--) {
            cout << b[i] << " ";
        }
        cout << "\n";
    }
    else {
        for (ll i = 0; i < N; i++) {
            cout << b[i] << " ";
        }
        cout << "\n";
    }
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