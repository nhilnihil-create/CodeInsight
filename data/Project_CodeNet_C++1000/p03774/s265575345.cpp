#include <bits/stdc++.h>
using namespace std;

int n, m, ans[55];
pair<int, int> s[55], c[55];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i].first >> s[i].second;
    }

    for (int i = 0; i < m; i++) {
        cin >> c[i].first >> c[i].second;
    }

    for (int i = 0; i < n; i++) {
        int id = -1, cur = 1e9;
        for (int j = 0; j < m; j++) {
            if (abs(s[i].first - c[j].first) + abs(s[i].second - c[j].second) < cur) {
                id = j;
                cur = abs(s[i].first - c[j].first) + abs(s[i].second - c[j].second);
            }
        }

        ans[i] = id;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1 << '\n';
    }

    return 0;
}