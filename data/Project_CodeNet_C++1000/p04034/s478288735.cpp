#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, ans = 0;
    cin >> n >> m;
    vector<pair<int, bool>> box(n, make_pair(1, false));
    box[0] = make_pair(1, true);
    for (auto i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        box[y].first += 1;
        box[x].first -= 1;
        box[y].second |= box[x].second;
        if (box[x].first == 0) box[x].second = false;
        // for (auto j = 0; j < n; j++) {
        //     cout << box[j].first << " " << box[j].second
        //          << endl;
        // }
    }
    for (auto i = 0; i < n; i++)
        ans += (box[i].second ? 1 : 0);
    cout << ans << endl;
    return 0;
}