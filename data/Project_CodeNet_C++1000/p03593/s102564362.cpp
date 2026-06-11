#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>
#include <cassert>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int h, w;
    cin >> h >> w;
    int cnt[26] = {0};
    rep(i, h) rep(j, w) {
        char c;
        cin >> c;
        ++cnt[c-'a'];
    }
    int cnt4;
    int cnt2;
    if (!(h&1) && !(w&1)) {
        rep(i, 26) {
            //cout << cnt[i] << endl;
            if (cnt[i] % 4 != 0) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    else if ((h&1) && (w&1)) {
        cnt4 = h * w - h - w + 1;
        cnt2 = h + w - 1;
        bool flg1 = false;
        rep(i, 26) {
            if (cnt4 - (cnt[i] / 4) * 4 < 0) {
                cnt[i] -= cnt4;
                cnt4 = 0;
            }
            else {
                cnt4 -= (cnt[i] / 4) * 4;
                cnt[i] -= (cnt[i] / 4) * 4;
            }
            if (cnt2 - (cnt[i] / 2) * 2 < 0) {
                cnt[i] -= cnt2;
                cnt2 = 0;
            }
            else {
                cnt2 -= (cnt[i] / 2) * 2;
                cnt[i] -= (cnt[i] / 2) * 2;
            }
            if (cnt[i]) {
                if (!flg1) {
                    flg1 = true;
                }
                else {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
        if (!flg1) {
            cout << "No" << endl;
            return 0;
        }
    }
    else {
        if (h&1) {
            cnt4 = h * w - w;
            cnt2 = w;
        }
        else {
            cnt4 = h * w - h;
            cnt2 = h;
        }
        rep(i, 26) {
            //cout << cnt[i] << endl;
            if (cnt4 - (cnt[i] / 4) * 4 < 0) {
                cnt[i] -= cnt4;
                cnt4 = 0;
            }
            else {
                cnt4 -= (cnt[i] / 4) * 4;
                cnt[i] -= (cnt[i] / 4) * 4;
            }
            if (cnt[i]&1) {
                cout << "No" << endl;
                return 0;
            }
            if (cnt2 - cnt[i] < 0) {
                cout << "No" << endl;
                return 0;
            }
            cnt2 -= cnt[i];
        }
    }
    cout << "Yes" << endl;
    return 0;
}
