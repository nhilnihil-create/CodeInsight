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
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l  >> r;
        ans += (r - l + 1);
    }
    cout << ans << endl;
}