#include <bits/stdc++.h>

#define rep(i, N) for (ll i = 0; i < N; i++)
#define rep1(i, N) for (ll i = 1; i <= N; i++)
#define repr(i, N) for (ll i = N-1; i >= 0; i--)
#define repr1(i, N) for (ll i = N; i > 0; i--)

#define MOD 998244353

using ll = long long;
using namespace std;

typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<P> vpi;
typedef pair<ll,ll> Pl;
typedef vector<ll> vl;
typedef vector<Pl> vpl;

ll gcd(ll a, ll b){
    if(a < b) swap(a, b);
    if(b <= 0) return -1;
    ll r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

ll lcm(ll a, ll b){
    return (a/gcd(a,b)*b);
}


int main() {
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    int dx = tx - sx, dy = ty - sy;
    string ans;
    rep(i, dy) ans += "U";
    rep(i, dx) ans += "R";
    rep(i, dy) ans += "D";
    rep(i, dx) ans += "L";

    ans += "L";
    rep(i, dy+1) ans += "U";
    rep(i, dx+1) ans += "R";
    ans += "D";
    ans += "R";
    rep(i, dy+1) ans += "D";
    rep(i, dx+1) ans += "L";
    ans += "U";

    //string ans = ( flag ? "Yes" : "No" );
    //printf("%.8lf\n", ans);
    cout << ans << "\n";
    return 0;
}
