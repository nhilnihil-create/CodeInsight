#include <bits/stdc++.h>
using namespace std;
constexpr int B = 20;

int main() {
    int n, l, q;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> l >> q;
    
    vector<vector<int>> data(B, vector<int>(n));
    for (int i = 0; i < n; i++) {
        int ok = a[i] + l;
        data[0][i] = (prev(upper_bound(a.begin(), a.end(), ok)) - a.begin());
    }
    for (int i = 1; i < B; i++) for (int j = 0; j < n; j++) {
        if (data[i-1][j] == n-1) data[i][j] = data[i-1][j];
        else data[i][j] = data[i-1][data[i-1][j]];
    }
    
    // ホテル i から x 日でどの旅館まで行けるか
    auto bs = [&] (int i, int x) {
        for (int s = 0; s < B; s++) {
            if (x&(1<<s)) i = data[s][i];
        }
        return i;
    };
    
    auto query = [&] (int a, int b) {
        int ok = n, ng = 0;
        while (abs(ok - ng) > 1) {
            int mid = (ok + ng) / 2;
            if (bs(a, mid) >= b) ok = mid;
            else ng = mid;
        }
        return ok;
    };
    
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        cout << query(--a, --b) << endl;
    }
    return 0;
}