#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int n, m, k;
    bool chk = false;

    cin >> n >> m >> k;

    for (int x = 0; x <= n; x++) {
        for (int y = 0; y <= m; y++) {
            if (m * x + n * y - x * y * 2 == k) {
                chk = true;
                break;
            }
        }
        if (chk == true) break;
    }

    if (chk == true)
        cout << "Yes";
    else
        cout << "No";
    //
}
