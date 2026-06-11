#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int (i)=(a);i<(int)(b);i++)
#define rep(i,n) FOR(i,0,n)

int h, w, n;
using P = pair<int, int>;

int main() {
    cin >> h >> w >> n;
    
    map<P, int> mp;
    rep(k, n) {
        int x, y;
        scanf("%d%d", &y, &x);
        x--; y--;
        FOR(dy, max(0, y - 2), min(h - 3, y) + 1) {
            FOR(dx, max(0, x - 2), min(w - 3, x) + 1) {
                mp[P(dy, dx)]++;
            }
        }
    }

    long long res[10] = {0};
    for (auto&& p : mp) {
        res[p.second]++;
        res[0]++;
    }

    res[0] = 1LL * (h - 2)*(w - 2) - res[0];
    for (auto&& i : res) {
        cout << i << endl;
    }


    return 0;
}