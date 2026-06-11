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
    ll mn = L_INF;
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
        mn = min(mn, A[i]);
    }

    ll cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (ll i = 0; i < N; i++) {
        if (A[i] == mn) {
            ++cnt1;
        }
        else if (A[i] == mn + 1) {
            ++cnt2;
        }
        else {
            ++cnt3;
        }
    }

    if (cnt3 > 0) {
        cout << "No\n";
        return;
    }

    if (cnt2 == 0) {
        if (mn + 1 == N) {
            cout << "Yes\n";
        }
        else if (2 * mn <= N) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
        return;
    }

    ll c = mn + 1;
    if (cnt1 >= c) {
        cout << "No\n";
    }
    else if (cnt2 < (c - cnt1) * 2) {
        cout << "No\n";
    }
    else {
        cout << "Yes\n";
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