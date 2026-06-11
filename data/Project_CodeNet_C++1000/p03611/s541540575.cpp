#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    while(n--) {
        int x;
        cin >> x;
        int i = x - 1;
        while(i < x + 2) {
            mp[i]++;
            i++;
        }
    }
    int ans = 0;
    for (auto p : mp) {
        ans = max(ans, p.second);
    }
    cout << ans;

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
