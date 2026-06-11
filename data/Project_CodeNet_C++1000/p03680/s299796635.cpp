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
    int n;
    cin >> n;
    vi a(n*2);
    vi check(n*2);
    rep(i,n) cin >>a[i];
    int ans = 0;
    for(int i = 1; ; i = a[i-1]) {
        check[i-1]++;
        if(check[i-1] == 2) {
            ans = -1;
            break;
        }
        else if (i == 2) {
            break;
        }
        ans++;
    }
    cout <<  ans << endl;
}