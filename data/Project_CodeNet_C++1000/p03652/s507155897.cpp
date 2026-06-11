#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    vector <vector <int>> a(n, vector <int> (m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            --a[i][j];
        }
    }
    int ans = n;
    vector <int> cnt(m);
    vector <int> hv(m, 1);
    auto relax = [&] () {
        for (int i = 0; i < m; ++i) cnt[i] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (hv[a[i][j]]) {
                    ++cnt[a[i][j]];
                    break;
                }
            }
        }
    };
    for (int i = 0; i < m; ++i) {
        relax();
        ans = min(ans, *max_element(cnt.begin(), cnt.end()));
        int id = max_element(cnt.begin(), cnt.end()) - cnt.begin();
        hv[id] = 0;
    }
    cout << ans << '\n';
}