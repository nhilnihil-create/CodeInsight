#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    while(n--) {
        int x;
        cin >> x;
        mp[x]++;
    }
    int ans = 0;
    for (auto x : mp) {
        if(x.second % 2) {
            ans++;
        }
    }
    cout << ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
