#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int H, W;
    cin >> H >> W;
    int cnt[26] = {};
    for(int i = 0; i < H; i++) for(int j = 0; j < W; j++) {
        char c;
        cin >> c;
        cnt[c - 'a']++;
    }

    int four = (H / 2) * (W / 2);
    int two = (H & 1 ? W / 2 : 0) + (W & 1 ? H / 2 : 0);
    int one = (H & 1) && (W & 1);
    for(int i = 0; i < 26 && four; i++) {
        int n = min(four, cnt[i] / 4);
        cnt[i] -= n * 4;
        four -= n;
    }
    for(int i = 0; i < 26 && two; i++) {
        int n = min(two, cnt[i] / 2);
        cnt[i] -= n * 2;
        two -= n;
    }
    for(int i = 0; i < 26 && one; i++) {
        if(cnt[i] & 1) {
            one = 0;
            cnt[i]--;
            break;
        }
    }
    return one == 0 &&
           two == 0 &&
           four == 0;
}

int main() {
    cout << (solve() ? "Yes" : "No") << endl;
    return 0;
}
