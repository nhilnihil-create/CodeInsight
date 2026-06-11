#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;


int main() {
    string S;
    cin >> S;

    int ans = 1000;
    int char_int[30] = {};

    for (char c='a'; c <='z'; c++) {
        int idx = c - 'a';
        int prev = 0, now = 0;

        rep(i, S.size()) {
            if (S[i] == c) {
                now = i;
                char_int[idx] = max(char_int[idx], now - prev);
                prev = now + 1;
            }
        }
        if (prev != 0) char_int[idx] = max(char_int[idx], ((int) S.size()) - prev);
    }

    rep(i, 'z'-'a'+1) {
        if (char_int[i] != 0) ans = min(ans, char_int[i]);
    }

    if (ans == 1000) ans = 0;
    cout << ans << endl;

    return 0;
}