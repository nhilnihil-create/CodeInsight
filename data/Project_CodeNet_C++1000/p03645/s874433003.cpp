#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, m; cin >> n >> m;
    vector<bool> a(n+1);
    vector<bool> b(n+1);
    rep(i, m) {
        int tmp_a, tmp_b;
        cin >> tmp_a >> tmp_b;
        if (tmp_a == 1) a[tmp_b] = true;
        if (tmp_b == n) b[tmp_a] = true;
    }
    rep(i, a.size()) {
        if (a[i] && b[i]) {
            puts("POSSIBLE");
            return 0;
        }
    }
    puts("IMPOSSIBLE");
}