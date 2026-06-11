#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
void Main()
{
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    ll dx = tx - sx;
    ll dy = ty - sy;
    rep(i, dx) cout << "R";
    rep(i, dy) cout << "U";

    rep(i, dx) cout << "L";
    rep(i, dy) cout << "D";

    cout << "D";
    rep(i, dx+1) cout << "R";
    rep(i, dy+1) cout << "U";
    cout << "L";

    cout << "U";
    rep(i, dx+1) cout << "L";
    rep(i, dy+1) cout << "D";
    cout << "R";

    cout << endl;
}
signed main(){ Main();return 0;}