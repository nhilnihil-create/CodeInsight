#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int main()
{
    int W, H; cin >> W >> H;
    vector<pair<int, int>> A;
    for (int i = 0; i < W; i++) {
        int p; cin >> p;
        A.emplace_back(p, 0);
    }
    for (int i = 0; i < H; i++) {
        int q; cin >> q;
        A.emplace_back(q, 1);
    }
    sort(begin(A), end(A));
    Int ans = 0;
    for (int i = 0; i < A.size(); i++) {
        Int cost, axis; tie(cost, axis) = A[i];
        if (axis == 0) {
            if (W > 0) ans += cost * (H+1);
            W--;
        } else {
            if (H > 0) ans += cost * (W+1);
            H--;
        }
    }
    cout << ans << '\n';
    return 0;
}