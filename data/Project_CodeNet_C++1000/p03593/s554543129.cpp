#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int h, w;
    cin >> h >> w;
    vector<int> cnt(26, 0);
    rep(i, h) {
        string s;
        cin >> s;
        for ( char c: s ) {
            ++cnt[c-'a'];
        }
    }
    if ( (h*w) % 2 == 1 ) {
        rep(i, 26 ) {
            if ( cnt[i] % 2 == 1 ) {
                --cnt[i];
                break;
            }
        }
    }
    rep(i, 26) {
        if ( cnt[i] % 2 == 1 ) {
            cout << "No" << endl;
            return 0;
        }
    }
    int k2 = 0;
    if ( h % 2 == 1 ) {
        k2 += w / 2;
    }
    if ( w % 2 == 1 ) {
        k2 += h / 2;
    }
    int have2 = 0;
    rep(i, 26) {
        have2 += (cnt[i] % 4 == 2);
    }
    if ( have2 > k2 ) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}
