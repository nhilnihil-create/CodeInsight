#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x.at(i);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += min(x.at(i) * 2, abs(k - x.at(i)) * 2);
    }
    cout << ans << endl;
    return 0;
}