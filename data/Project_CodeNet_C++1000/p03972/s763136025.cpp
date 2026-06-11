#include <bits/stdc++.h>

using namespace std;

#define all(c) (c).begin(), (c).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

using Int = long long;
int W, H;
vector<Int> p, q;
int main() {
    cin >> W >> H;
    p.resize(W), q.resize(H);
    rep(i, W) cin >> p[i];
    rep(i, H) cin >> q[i];
    sort(all(q));
    sort(all(p));
    Int ans = 0;
    int i = 0, j = 0;
    while (i < H || j < W) {
        if (i == H) {
            ans += p[j];
            j++;
        } else if (j == W) {
            ans += q[i];
            i++;
        } else {
            if (q[i] < p[j]) {
                ans += (W - j + 1) * q[i];
                i++;
            } else {
                ans += (H - i + 1) * p[j];
                j++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
