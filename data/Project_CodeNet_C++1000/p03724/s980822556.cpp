#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main() {
    int n, m; cin >> n >> m;
    vector<int> a(n, 0);
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        x--; y--;
        a[x]++;
        a[y]++;
    }
    for (int i = 0; i < n; i++) {
        if ((a[i] & 1) != 0) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}