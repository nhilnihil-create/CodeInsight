#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1000000000 + 7;

bool debug = 0;

void solve() {
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < (int)s.size() - 1; i++) {
        if (s[i] != s[i + 1]) cnt++;
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