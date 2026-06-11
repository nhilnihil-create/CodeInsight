#include "bits/stdc++.h"

using namespace std;

using ll = long long;

template<typename T> using V = std::vector<T>;
using Vi = V<int>;
using VVi = V<V<int>>;
using Vl = V<ll>;
using VVl = V<V<ll>>;
using Vs = V<string>;

template<typename T1, typename T2> using P = std::pair<T1, T2>;
using Pii = P<int, int>;
using Pll = P<ll, ll>;
using Pdd = P<double, double>;

template<typename T1, typename T2> using M = std::map<T1, T2>;
using Mii = M<int, int>;
using Mll = M<ll, ll>;
using Msi = M<string, int>;

#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define REP2(i,s,e) for(int i=(int)(s);i<(int)(e);++i)
#define RREP(i,s,e) for(int i=(int)(s);i>=(int)(e);--i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin(),ie=(c).end();i!=ie;++i)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin(),ie=(c).rend();i!=ie;++i)
#define ALL(c) (c).begin(), (c).end()

const double PI = acos(-1);
const ll MOD = 1e9+7;

int n, h, w;

int main() {
    cin >> h >> w >> n;
    Vi a(n);
    REP(i, n) cin >> a[i];

    int x = 0, y = 0;
    REP(i, h) {
        V<string> s(w);
        REP(j, w) {
            s[j] = to_string(x+1);
            y++;
            if (y == a[x]) {
                x++;
                y = 0;
            }
        }
        if (i % 2 == 0) {
            REP(j, w) {
                cout << s[j];
                if (j != w-1) {
                    cout << ' ';
                }
            }
        } else {
            RREP(j, w-1, 0) {
                cout << s[j];
                if (j != 0) {
                    cout << ' ';
                }
            }
        }
        cout << '\n';
    }

    return 0;
}
