#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    map<char, int> cnt;
    set<char> se;
    for (int i = 0; i < H; i++) cin >> S[i];
    for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) {
        if (cnt.count(S[i][j])) cnt[S[i][j]]++;
        else cnt[S[i][j]] = 1;
        se.insert(S[i][j]);
    }
    
    int s = 0, t = 0;
    for (auto c : se) {
        int m = cnt[c] % 4;
        if (m == 1) s++;
        if (m == 2) t++;
        if (m == 3) { s++; t++; }
    }
    
    int f, g;
    if (H % 2 == 1 && W % 2 == 1) {
        f = 1; g = (H/2) + (W/2);
    } else if (H % 2 == 0 && W % 2 == 0) {
        f = 0, g = 0;
    } else {
        f = 0;
        if (H % 2 == 0) g = H/2;
        else g = W/2;
    }
    
    if (f == s && g >= t) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}