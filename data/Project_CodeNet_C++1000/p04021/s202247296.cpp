// 1 3 4 5 2
// 1 3 4 2 5  -1
// 1 2 4 3 5  -1
// 1 2 3 4 5  -2
#include <bits/stdc++.h>
typedef long long lint;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
// 1-indexedで座標圧縮してmax(奇数座標にある偶数の数,偶数座標にある奇数の数)
// 奇数座標にある偶数の数 == 偶数座標にある奇数の数じゃん.........
// 座標圧縮使う問題初めて解いた
// デバッグ用に要素数減らした後戻してなかった......................................
int main() {
    int n; cin >> n;
    int a[100000];
    rep(i,n) cin >> a[i];

    int sorta[100000];
    rep(i,n) sorta[i] = a[i];
    sort(sorta, sorta+n);
    map<int,int> zip;
    rep(i,n) zip[sorta[i]] = i+1;
    rep(i,n) a[i] = zip[a[i]];
    int ans = 0;
    rep(i,n) {
        if (a[i]%2 != (i+1)%2) ans ++;
    }
    cout << ans/2 << endl;
}