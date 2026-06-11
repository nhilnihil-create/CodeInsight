#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    string ans;
    //1往復目
    rep(i, (ty-sy)) ans.push_back('U');
    rep(i, (tx-sx)) ans.push_back('R');
    rep(i, (ty-sy)) ans.push_back('D');
    rep(i, (tx-sx)) ans.push_back('L');

    //2往復目
    ans.push_back('L');
    rep(i, (ty-sy+1)) ans.push_back('U');
    rep(i, (tx-sx+1)) ans.push_back('R');
    ans.push_back('D');
    ans.push_back('R');
    rep(i, (ty-sy+1)) ans.push_back('D');
    rep(i, (tx-sx+1)) ans.push_back('L');
    ans.push_back('U');
    cout << ans << endl;
    return 0;
}