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
    string S;
    cin >> S;

    Vi stats(N, -1);
    bool ok = false;

    constexpr ll edges[][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};

    for (ll idx = 0; idx < 4; idx++) {
        stats.assign(N, -1);
        stats[0] = edges[idx][0], stats[N - 1] = edges[idx][1];
        for (ll i = 0; i < N - 1; i++) {
            ll left = i - 1, right = i + 1;
            if (left < 0) left = N - 1;
            if (right >= N) right = 0;
            if (stats[i] == 0) {
                if (S[i] == 'o') {
                    stats[right] = stats[left];
                }
                else {
                    stats[right] = 1 - stats[left];
                }
            }
            else {
                if (S[i] == 'o') {
                    stats[right] = 1 - stats[left];
                }
                else {
                    stats[right] = stats[left];
                }
            }
        }

        if (stats[N - 1] == edges[idx][1]) {
            if (S[N - 1] == 'o') {
                if (stats[N - 1] == 0) {
                    if (stats[N - 2] == stats[0]) ok = true;
                }
                else {
                    if (stats[N - 2] != stats[0]) ok = true;
                }
            }
            else {
                if (stats[N - 1] == 0) {
                    if (stats[N - 2] != stats[0]) ok = true;
                }
                else {
                    if (stats[N - 2] == stats[0]) ok = true;
                }
            }
        }

        if (ok) {
            break;
        }
    }

    if (ok) {
        for (ll i = 0; i < N; i++) {
            cout << (stats[i] == 0 ? 'S' : 'W');
        }
        cout << "\n";
    }
    else {
        cout << -1 << "\n";
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