#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if(mp[x] % 2) {
            mp[x]--;
        } else {
            mp[x]++;
        }
    }
    int ans = 0;
    for (auto p : mp) {
        if (p.second > 0) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
