#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int prev = 0; long long ans = 0;
    for (int i = 0; i < n; i++) {
        int t = prev + 1;
        int s = v[i] - t;
        if (s > 0) {
            ans += (s + t-1) / t;
            v[i] = 1;
        }
        prev = max(v[i], prev);
    }
    cout << ans << endl;
    return 0;
}