#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    ll x, y; cin >> x >> y;
    ll res = 0;

    if (y == 0) {
        if (x < 0) res = -x;
        else if (x == 0) res = 0;
        else res = x + 1;
    } else if (y < 0) {
        if (x < 0) {
            if (x < y) res = abs(x) - abs(y);
            else if (x == y) res = 0;
            else res = abs(y) - abs(x) + 2;
        } else if (x == 0) res = abs(y) + 1;
        else { // y is negative and x > y
            if (x < 0) res = abs(y) - abs(x) + 2;
            else if (x == 0) res = abs(y) + 1;
            else { // y is negative and x > y and x > 0
                if (abs(y) > x) res = abs(y) - x + 1;
                else res = x - abs(y) + 1;
            }
        }
    } else { // y > 0
        if (x < 0) {
            if (abs(x) < y) res = y - abs(x) + 1;
            else res = abs(x) - y + 1;
        } else if (x == 0) res = y;
        else { // y > 0 && x > 0
            if (x < y) res = y - x;
            else res = x - y + 2;
        }
    }

    cout << res << endl;
}