#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    string S; cin >> S;
    int g = 0, p = 0;
    int pable = 0;

    int score = 0;
    char mine;
    rep(i, S.size()) {
        char yours = S.at(i);
        if (pable >= S.size() - i) {
            mine = 'p';
        } else {
            mine = yours;
        }
        if (yours == 'p') {
            if (mine == 'g') score--, pable++;
            else pable--;
        } else {
            if (mine == 'g') pable++;
            else score++, pable--;
        }
    }
    cout << score << endl;
}
