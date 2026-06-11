#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int prest = 0, gg_cnt = 0, score = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'g') {
            prest++;
            gg_cnt++;
        } else if (prest > 0) {
            prest--;
        } else {
            score--;
        }
    }
    score += prest / 2;
    cout << score << endl;
}