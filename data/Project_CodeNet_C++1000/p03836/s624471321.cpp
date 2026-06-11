#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;
vector<int> dx = {1,0};
vector<int> dy = {0,1};


int main(){
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    
    rep(i,tx-sx) cout << 'R';
    rep(i,ty-sy) cout << 'U';
    rep(i,tx-sx) cout << 'L';
    rep(i,ty-sy) cout << 'D';
    cout << 'D';
    rep(i,tx-sx+1) cout << 'R';
    rep(i,ty-sy+1) cout << 'U';
    cout << 'L';
    cout << 'U';
    rep(i,tx-sx+1) cout << 'L';
    rep(i,ty-sy+1) cout << 'D';
    cout << 'R';
}