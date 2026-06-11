#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)

typedef pair<int,int> P;
typedef long long ll;

const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    int sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;

    int x1 = tx-sx;
    int y1 = ty-sy;
    rep(i,x1) {
        cout << 'R';
    }
    rep(i,y1) {
        cout << 'U';
    }
    cout << 'L';
    
    rep(i,y1-1) {
        cout << 'D';
    }
    rep(i,x1-1) {
        cout << 'L';
    }
    cout << 'D';

    cout << 'L';
    rep(i,y1+1) {
        cout << 'U';
    }
    rep(i,x1+1) {
        cout << 'R';
    }
    cout << 'D';
    cout << 'R';
    rep(i,y1+1) {
        cout << 'D';
    }
    rep(i,x1+1) {
        cout << 'L';
    }
    cout << 'U' << endl;
}
