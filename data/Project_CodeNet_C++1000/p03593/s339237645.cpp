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

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int h, w;
    cin >> h >> w;
    vector<int> cnt(26, 0);
    rep(i, h) rep(j, w) {
        char c;
        cin >> c;
        ++cnt[c-'a'];
    }
    //rep(i, 26) cout << cnt[i] << " " ;
    //cout << endl;
    bool odd_odd = (h % 2 != 0 && w % 2 != 0) ? true : false;
    bool odd = false;
    if (h % 2 == 0 && w % 2 == 0) {
        rep(i, 26) {
            if (cnt[i] % 4 != 0) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    else {
        int lim_num;
        if (h % 2 != 0 && w % 2 != 0) {
            lim_num = h * w - (h + w - 1);
        }
        else if (h % 2 != 0 && w % 2 == 0) {
            lim_num = h * w - w;
        }
        else {
            lim_num = h * w - h;
        }
        int tmp_cnt = 0;
        bool ok = false;
        rep(i, 26) {
            if (cnt[i] >= 4) {
                tmp_cnt += cnt[i] / 4 * 4;
                cnt[i] -= cnt[i] / 4 * 4;
            }
            if (tmp_cnt >= lim_num) {
                cnt[i] += tmp_cnt - lim_num;
                ok = true;
                break;
            }
        }
        if (!ok) {
            cout << "No" << endl;
            return 0;
        }
        rep(i, 26) {
            if (cnt[i]&1) {
                if (!odd_odd) {
                    cout << "No" << endl;
                    return 0;
                }
                else if (!odd) {
                    odd = true;
                }
                else {
                    cout << "No" << endl;
                    return 0;
                }
            } 
        }
    }
    if (odd_odd) cout << ((odd) ? "Yes" : "No") << endl;
    else         cout << "Yes" << endl;

    return 0;
}
