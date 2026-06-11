#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct query {
    int l, r, t;
};

int main() {
    int n, m; cin >> n >> m;
    vector<query> v;
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        v.push_back({l, r, 0});
    }
    for (int d = 2; d <= m; d++)
        for (int k = 0; k * d < m; k++)
            v.push_back({k * d + 1, (k + 1) * d - 1, d});
    sort(v.begin(), v.end(), [](query lhs, query rhs) {
            return (lhs.r < rhs.r) || (lhs.r == rhs.r && lhs.t < rhs.t);
        });
    int ans[m+1], bit[m+1];
    fill(bit, bit+m+1, 0);
    fill(ans, ans+m+1, n);
    for (query q : v) {
        if (q.t == 0)
            for (int x = q.l; x > 0; x -= x&-x) bit[x]++;
        else {
            for (int x = q.l; x <= m; x += x&-x) ans[q.t] -= bit[x];
        }
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << endl;
}
