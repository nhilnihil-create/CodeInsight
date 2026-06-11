#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
const long long LINF = 1e18;
#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOREACH(x,a) for(auto& (x) : (a) )
typedef long long ll;
using namespace std;
typedef pair<ll, ll> P;

int main(int argc, char const *argv[]) {
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    // A + C*pl - D*mi <= B <= A + D*pl - C*mi
    bool ok = false;

    REP(i,n) {
        ll pl = i;
        ll mi = n-1-i;
        if (a+c*pl-d*mi <= b && b <= a+d*pl-c*mi) {
            ok = true;
            break;
        }
    }

    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}