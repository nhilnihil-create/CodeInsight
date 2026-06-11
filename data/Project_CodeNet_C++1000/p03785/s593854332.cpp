#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1000000000 + 7;

bool debug = 0;

void solve() {
    int n, c, k;
    cin >> n >> c >> k;
    vector<int> t(n);
    for (int i = 0; i < n; i++) cin >> t[i];
    sort(t.begin(), t.end());
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int time = t[i];
        for (int j = 0; j < c; j++) {
            if (t[i + j] > time + k) {
                i += j - 1;
                break;
            }
            if (j == c - 1) i += j;
        }
        cnt++;
    }
    cout << cnt << endl;
}

int main() {
    if (debug) {
        while (true) {
            cout << "********" << endl;
            solve();
        }
    } else {
        solve();
    }
    return 0;
}