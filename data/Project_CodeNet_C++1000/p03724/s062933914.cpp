#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    int n, m; cin >> n >> m;

    vector<int> c(n, 0);
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        --a; --b;

        c[a]++;
        c[b]++;
    }

    bool ok = true;
    for (int i = 0; i < n; ++i) {
        if (c[i] % 2 == 1) {
            ok = false;
            break;
        }
    }

    if (ok) {
        puts("YES");
    } else {
        puts("NO");
    }
}