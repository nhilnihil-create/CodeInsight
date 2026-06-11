#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve() {
    int n,m;
    cin >> n >> m;
    int f[n+1], l[n+1];
    for (int i=0; i<n+1; ++i) {
        f[i] = l[i] = 0;
    }
    for (int i=0; i<m; ++i) {
        int ai, bi;
        cin >> ai >> bi;
        if (ai == 1) {
            f[bi] = 1;
        }
        if (bi == n) {
            l[ai] = 1;
        }
    }
    for (int i=0; i < n+1; ++i) {
        if (f[i] == 1 && l[i] == 1) {
            cout << "POSSIBLE";
            return;
        }
    }
    cout << "IMPOSSIBLE";
}

int main() {

	solve();
    return 0;
}
