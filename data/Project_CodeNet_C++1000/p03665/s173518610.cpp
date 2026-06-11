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

ll combination ( ll a, ll b) {
    ll ret = 1LL;
    if ( a / 2 < b ) {
        b = a - b;
    }
    else {

    }
    for ( int i = 0; i < b; ++i ) {
        ret *= a;
        --a;
    }
//    cout << ret << endl;
    while(1) {
        if ( b == 0 ) break;
        ret /= b;
        --b;
    }
    return ret;
}

int main(){
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    int odd_num = 0;
    rep(i, n) {
        cin >> a[i];
        if ( a[i]&1 ) {
            ++odd_num;
        }
    }
    ll ans = 1LL;
    ll tmp_ans = 0;
    if ( p == 1 && odd_num == 0 ) {
        cout << 0 << endl;
        return 0;
    }
    if ( p == 0 ) {
        rep(i, n - odd_num) {
            ans *= 2LL;
        }
//        cout << ans << endl;
        for ( int i = 0; i <= odd_num; i += 2 ) {
//            cout << combination((ll)odd_num, (ll)i) << endl;
            tmp_ans += combination((ll)odd_num, (ll)i);
        }
//        cout << tmp_ans << endl;
        ans *= tmp_ans;
    }
    else {
//        cout << odd_num << endl;
        rep(i, n - odd_num) {
            ans *= 2LL;
        }
        for ( int i = 1; i <= odd_num; i += 2 ) {
            tmp_ans += combination((ll)odd_num, (ll)i);
//            cout << tmp_ans << endl;
        }
//        cout << tmp_ans << endl;
        ans *= tmp_ans;
    }
    cout << ans << endl;
    return 0;
}
