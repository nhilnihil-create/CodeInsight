#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ans, free, ai;
    ans = 0; free = 0;
    scanf("%d", &n);
    vector<int> color(8);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ai);
        for (int j = 0; j < 8; j++) {
            if (400 * j <= ai && ai < 400 * (j + 1)) {
                color.at(j) = 1;
            }
        }
        if (3200 <= ai) free++;
    }
    ans = accumulate(color.begin(), color.end(), 0);
    if (ans == 0) {
        ans = 1;
        free--;
    }
    cout << ans << " " << ans+free << endl;
    return 0;
}