#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
using namespace std;
// マクロ
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
// 型エイリアス
using ll = long long;
using vi = vector<int>;
using vs = vector<string>;
using vvi = vector<vi>;
using vvs = vector<vs>;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i,h) cin >> a[i];
    rep(i, w+2) {
        cout << '#';
        if(i == w + 1) cout << endl;
    }
    for(int i = 0; i < h; i++) {
        cout << '#' << a[i] <<'#' << endl;
    }
    rep(i, w+2) {
        cout << '#';
        if(i == w + 1) cout << endl;
    }
}