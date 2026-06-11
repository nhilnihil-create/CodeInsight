#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    map<long long, long long> mp;
    mp[0] = 0;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        mp[x]++;
    }
    auto i = mp.end();
    vector<long long> ans(3);
    int cnt = 0;
    while(i != mp.begin() && cnt < 2) {
        while(mp[(*i).first] >= 2 && cnt < 2) {
            ans[cnt] = (*i).first;
            cnt++;
            mp[(*i).first] -= 2;
        }
        i--;
    }
    cout << ans[0] * ans[1];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
