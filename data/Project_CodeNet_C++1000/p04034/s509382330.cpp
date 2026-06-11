#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1000000000 + 7;

bool debug = 0;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<bool> red(n, false);
    vector<int> ball(n, 1);
    red[0] = true;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        if (red[x]) red[y] = true;
        --ball[x], ++ball[y];
        if (ball[x] == 0) red[x] = false;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (red[i]) cnt++;
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