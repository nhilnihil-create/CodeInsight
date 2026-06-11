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
    ll X, Y;
    cin >> X >> Y;
    ll ans = L_INF;
    if (Y == 0) {
        if (X == 0) {
            ans = 0;
        }
        else if (X > 0) {
            ans = X + 1;
        }
        else {
            ans = -X;
        }
    }
    else {
        if (X <= Y) {
            ans = min(ans, Y - X);
        }
        if (-X <= Y) {
            ans = min(ans, Y + X + 1);
        }
        if (X <= -Y) {
            ans = min(ans, -Y - X + 1);
        }
        if (-X <= -Y) {
            ans = min(ans, -Y + X + 2);
        }
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