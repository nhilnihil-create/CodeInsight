#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;
    string ans;
    int diff_x = tx-sx;
    int diff_y = ty-sy;
    rep(i,diff_x){
        ans+='R';
    }
    rep(i,diff_y){
        ans+='U';
    }
    rep(i,diff_x){
        ans+='L';
    }
    rep(i,diff_y){
        ans+='D';
    }
    ans += 'D';
    rep(i,diff_x){
        ans+='R';
    }
    ans+='R';
    rep(i,diff_y){
        ans+='U';
    }
    ans+='U';
    ans+='L';
    ans+='U';
    rep(i,diff_x){
        ans+='L';
    }
    ans+='L';
    rep(i,diff_y){
        ans+='D';
    }
    ans+='D';
    ans+='R';
    cout << ans << endl;
    return 0;
}