#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    int x = tx - sx, y = ty - sy;
    //1回目
    rep(i, x) cout << 'R';
    rep(i, y) cout << 'U';
    rep(i, x) cout << 'L';
    rep(i, y) cout << 'D';

    //2回目
    cout << 'D';
    rep(i, x + 1) cout << 'R';
    rep(i, y + 1) cout << 'U';
    cout << 'L';
    cout << 'U';
    rep(i, x + 1) cout << 'L';
    rep(i, y + 1) cout << 'D';
    cout << 'R';

    cout<<endl;
}