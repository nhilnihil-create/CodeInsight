#include "bits/stdc++.h"
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i ++) 

int main() {
        int h, w;
        cin >> h >> w;
        int ansh, answ;
        rep(i, h) rep(j, w) {
                string s;
                cin >> s;
                if (s == "snuke") {
                        ansh = i;
                        answ = j;
                        break;
                }
        }
        char ans = 'A' + answ;
        cout << ans << ansh + 1 << endl;
        return 0;
}

