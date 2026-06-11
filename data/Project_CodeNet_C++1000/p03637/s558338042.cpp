#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    int cnt = 0;
    int cnt2 = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x % 4 == 0) {
            cnt++;
        } else {
            if (x % 2 == 0) {
                cnt2++;
            }
        }
    }
    if (cnt + (cnt2/2) >= n/2) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}
