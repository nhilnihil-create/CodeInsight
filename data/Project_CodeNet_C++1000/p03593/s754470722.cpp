#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 1e5 + 5;
const int INF = 1001001001;
const int MOD = 1e9 + 7;

int main(){
    int H, W;
    cin >> H >> W;

    vector<string> a(H);
    rep(i, H) cin >> a[i];

    vector<int> b(30);
    rep(i, H) {
        rep(j, W) {
            char c = a[i][j];
            b[c - 'a']++;
        }
    }

    int g1, g2, g4;
    
    if (H * W % 2 == 1) {
        g1 = 1;
        g2 = H / 2 + W / 2;
        g4 = H / 2 * W / 2;
    } else if (H % 2 == 0 && W % 2 == 0) {
        g1 = 0;
        g2 = 0;
        g4 = H * W / 4;
    } else {
        g1 = 0;
        g2 = (H % 2 == 0)? H / 2 : W / 2;
        g4 = H / 2 * W / 2;
    }

    rep(i, g4) {
        rep(j, 30) {
            if (4 <= b[j]) {
                b[j] -= 4;
                break;
            }
        }
    }

    rep(i, g2) {
        rep(j, 30) {
            if (2 <= b[j]) {
                b[j] -= 2;
                break;
            }
        }
    }

    rep(i, g1) {
        rep(j, 30) {
            if (1 <= b[j]) {
                b[j] -= 1;
                break;
            }
        }
    }

    bool ans = true;
    rep(i, 30) {
        if (b[i] > 0) {
            ans = false;
            break;
        }
    }

    if (ans) {
        puts("Yes");
    } else {
        puts("No");
    }
}