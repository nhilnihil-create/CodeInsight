#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define ARRAY_LENGTH(array) sizeof(array)/sizeof(*array)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const int INF = 1000100100;

int main() {
    ll H, W;
    cin >> H >> W;

    char a[H][W];
    REP(i, H) REP(j, W) cin >> a[i][j];

    char c = '#';
    for(ll i = 0; i < H + 2; ++i) {
        printf("%c", c);
        for(ll j = 0; j < W; ++j) {
            if(i == 0 || i == H + 1) {
                printf("%c", c);
            } else {
                printf("%c", a[i - 1][j]);
            }
        }
        printf("%c\n", c);
    }

    return 0;
}