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
    int n, m;
    cin >> n >> m;
    vi ans(n);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >>a >> b;
        ans[a-1]++;
        ans[b-1]++;
    }
    rep(i,n) cout << ans[i] << endl;
}