#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, ma, mb; cin >> n >> ma >> mb;
    vector<tuple<int, int, int>> v(n);
    for (int i = 0; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        v[i] = make_tuple(a, b, c);
    }

    int nx = (n + 1) / 2, ny = n / 2;
    vector<pair<int, int>> x(1 << nx), y(1 << ny);
    for (int bits = 0; bits < (1 << nx); bits++) {
        for (int i = 0; i < nx; i++) {
            if ((bits >> i) & 1) {
                x[bits].first += mb * get<0>(v[i]) - ma * get<1>(v[i]);
                x[bits].second += get<2>(v[i]);
            }
        }
    }
    for (int bits = 0; bits < (1 << ny); bits++) {
        for (int i = 0; i < ny; i++) {
            if ((bits >> i) & 1) {
                y[bits].first += ma * get<1>(v[i + nx]) - mb * get<0>(v[i + nx]);
                y[bits].second += get<2>(v[i + nx]);
            }
        }
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    int ans = inf;
    for (int i = 0; i < (1 << nx); i++) {
        auto it = lower_bound(y.begin(), y.end(), make_pair(x[i].first, (int)(x[i].second == 0)));
        if (it != y.end() && x[i].first == (*it).first) {
            int res = x[i].second + (*it).second;
            ans = min(ans, res);
        }
    }
    cout << (ans < inf ? ans : -1) << endl;
    return 0;
}
