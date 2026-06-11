#include <bits/stdc++.h>
using namespace std;


void solve () {
    int n;
    cin >> n;
    map<int, int> mp;
    bool ok = 0;
    bool okk = 1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int c = x / 400;
        if (c >= 8) {
            ok = 1;
            mp[8]++;
        } else {
            mp[c]++;
            okk = 0;
        }
    }
    cout << mp.size() - ok + okk << " " << mp.size() + mp[8] - ok << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
