#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<n;i++)

int sx, tx, sy, ty;

signed main()
{
    cin >> sx >> sy >> tx >> ty;
    
    rep(i, tx - sx)cout << 'R';
    rep(i, ty - sy)cout << 'U';
    
    rep(i, tx - sx)cout << 'L';
    rep(i, ty - sy)cout << 'D';

    cout << 'D';
    rep(i, tx - sx + 1)cout << 'R';
    rep(i, ty - sy + 1)cout << 'U';
    cout << 'L';
    
    cout << 'U';
    rep(i, tx - sx + 1)cout << 'L';
    rep(i, ty - sy + 1)cout << 'D';
    cout << 'R' << endl;

    return 0;
}