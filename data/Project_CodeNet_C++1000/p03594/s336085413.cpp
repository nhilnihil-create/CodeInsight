#include <bits/stdc++.h>
using namespace std;
 
#define REP(i, n) for (ll i = 0; i < n; i++)
#define REPR(i, n) for (ll i = n; i >= 0; i--)
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define FORR(i, m, n) for (ll i = m; i >= n; i--)
#define REPO(i, n) for (ll i = 1; i <= n; i++)
#define ll long long
#define INF (ll)1 << 60
#define MINF (-1 * INF)
#define ALL(n) n.begin(), n.end()
#define MOD 1000000007
#define P pair<ll, ll>

ll h, w, d, t;
char c[4] = {'R', 'Y', 'G', 'B'};
int main() {
    cin >> h >> w >> d;
    if(d % 2 == 1){
        REP(i, h){
            REP(j, w){
                cout << ((i + j) % 2 == 0 ? 'R' : 'G');
            }
            cout << endl;
        }
        return 0;
    }
    REP(i, h){
        REP(j, w){
            ll x, y;
            if((i + j) % 2 == 0){
                x = (i - j) / 2;
                y = (i + j) / 2;
            }
            else {
                x = (i - 1 - j) / 2;
                y = (i - 1 + j) / 2;
            }
            ll s = ((x + d * 100000) / (d / 2) + 100000) % 2;
            ll t = ((y + d * 100000) / (d / 2) + 100000) % 2;
           cout << c[s * 2 + t];
        }
        cout << endl;
    }
}
