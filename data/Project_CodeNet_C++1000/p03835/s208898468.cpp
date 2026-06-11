#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int k, s;
    cin >> k >> s;
    int count = 0;
    for (int x = 0; x <= k && 3 * x <= s; x++) {
        for (int y = x; y <= k; y++) {
            for (int z = y; z <= k; z++) {
                if (x + y + z == s) {
                    if (x == y && y == z) count += 1;
                    else if (x == y && y != z) count += 3;
                    else if (y == z && z != x) count += 3;
                    else if (z == x && x != y) count += 3;
                    else count += 6;
                }
            }
        }
    }
    cout << count << endl;
}