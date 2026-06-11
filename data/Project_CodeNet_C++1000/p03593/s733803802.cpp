#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<int> cnt(26, 0);
    rep(i, H) rep(j, W) {
        char c;
        cin >> c;
        ++cnt[c - 'a'];
    }
    vector<int> mod_cnt(4, 0);
    rep(i, 26) ++mod_cnt[cnt[i] % 4];
    
    if (H % 2 && W % 2) {
        if (mod_cnt[2] <= (H - 1) / 2 + (W - 1) / 2 && mod_cnt[1] + mod_cnt[3] <= 1) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    } else if (H % 2) {
        if (mod_cnt[2] <= W / 2 && mod_cnt[1] + mod_cnt[3] <= 0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    } else if (W % 2) {
        if (mod_cnt[2] <= H / 2 && mod_cnt[1] + mod_cnt[3] <= 0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    } else {
        if (mod_cnt[1] + mod_cnt[2] + mod_cnt[3] <= 0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
