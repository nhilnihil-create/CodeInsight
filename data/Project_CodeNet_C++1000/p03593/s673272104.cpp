#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

map<int, int> n(int h, int w) {
    map<int, int> mp;
    if(h % 2 == 0 && w % 2 == 0) {
        mp[4] = h * w;
    } else if(h % 2 && w % 2) {
        mp[1] = 1;
        mp[2] = h + w - 2;
        mp[4] = h * w - mp[1] - mp[2];
    } else if(h % 2) {
        mp[2] = w;
        mp[4] = w * (h - 1);
    } else {
        mp[2] = h;
        mp[4] = h * (w - 1);
    }
    return mp;
}

int main() {
    int H, W;
    cin >> H >> W;
    map<char, int> cnt;
    rep(i, H) rep(j, W) {
        char c; cin >> c;
        cnt[c]++;
    }
    auto mp = n(H, W);
    for(auto &i : {4, 2, 1}) {
        for(int c = 'a'; c <= 'z'; ++c) {
            while(cnt[c] >= i && mp[i] >= i) {
                cnt[c] -= i;
                mp[i] -= i;
            }
        }
    }
    cout << (!mp[1] && !mp[2] && !mp[4] ? "Yes" : "No") << '\n';
    return 0;
}
