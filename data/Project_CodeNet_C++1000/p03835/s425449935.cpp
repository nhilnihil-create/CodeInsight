#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main() {
    int k, s;
    cin >> k >> s;
    int ans = 0;
    for (int x = 0; x <= floor(s / 3); x++) {
        for (int z = ceil(s / 3); z <= k; z++) {
            for (int y = x; y <= z; y++) {

                if (x + y + z == s) {
                    if (x == y && y == z) {
                        ans++;
                    } else if (x != y && y != z) {
                        ans += 6;
                    } else {
                        ans += 3;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
