#include <bits/stdc++.h>

//#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    queue<int> q[n];
    int cnt[m];
    for (int i = 0; i < m; i++) cnt[i] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            q[i].push(x-1);
            if (j == 0) cnt[x-1]++;
        }
    }
    int res = 1e9;
    set<int> bad;
    for (int iter = 0; iter < m-1; iter++) {
        int maxi = 0;
        int id = 0;
        for (int i = 0; i < m; i++) {
            if (cnt[i] > maxi) {
                maxi = cnt[i];
                id = i;
            }
        }
        bad.emplace(id);
        res = min(res, maxi);
        for (int i = 0; i < n; i++) {
            while (bad.count(q[i].front()) != 0) {
                cnt[q[i].front()]--;
                q[i].pop();
                cnt[q[i].front()]++;
            }
        }
    }int maxi = 0;
    int id = 0;
    for (int i = 0; i < m; i++) {
        if (cnt[i] > maxi) {
            maxi = cnt[i];
            id = i;
        }
    }
    bad.emplace(id);
    res = min(res, maxi);

    cout << res << '\n';
}
/*

 */