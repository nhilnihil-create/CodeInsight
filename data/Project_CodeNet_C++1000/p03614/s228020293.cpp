#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    bool same[n];
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        same[i] = a == i + 1;
    }
    int count = 0, ans = 0;
    for (bool t: same) {
        if (t) {
            count++;
        } else {
            ans += (count + 1) / 2;
            count = 0;
        }
    }
    ans += (count + 1) / 2;
    cout << ans << endl;
    return 0;
}
