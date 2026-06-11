#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m; cin >> n >> m;
    vector<deque<int>> v(n, deque<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    vector<bool> deleted(m+1, false);
    vector<int> count(m+1, 0);
    int q = m;
    int ans = 1e9;
    while (q--) {
        for (int i = 0; i < n; i++) {
            while (deleted[v[i].front()]) v[i].pop_front();
            count[v[i].front()]++;
        }
        int maxi = 0; int index = 0;
        for (int i = 1; i <= m; i++) {
            if (maxi < count[i]) {
                maxi = count[i]; index = i;
            }
            count[i] = 0;
        }
        ans = min(ans, maxi);
        deleted[index] = true;
    }
    cout << ans << endl;
    return 0;
}