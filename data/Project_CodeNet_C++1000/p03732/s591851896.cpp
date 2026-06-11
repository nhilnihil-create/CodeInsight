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

ll n, w;

int main() {
    cin >> n >> w;
    V<Pll> x(n);
    REP(i, n) cin >> x[i].first >> x[i].second;

    V<V<Pll>> y(4);
    REP(i, n) y[x[i].first - x[0].first].push_back(x[i]);
    REP(i, 4) sort(ALL(y[i]), greater<Pll>());

    ll w0 = 0, v0 = 0, maxi = -1;
    REP(i0, y[0].size()+1) {
        if (i0 > 0 && w0 + y[0][i0-1].first > w) break;
        if (i0 > 0) {
            w0 += y[0][i0-1].first;
            v0 += y[0][i0-1].second;
        }
        ll w1 = 0, v1 = 0;
        REP(i1, y[1].size()+1) {
            if (i1 > 0 && w0 + w1 + y[1][i1-1].first > w) break;
            if (i1 > 0) {
                w1 += y[1][i1-1].first;
                v1 += y[1][i1-1].second;
            }
            ll w2 = 0, v2 = 0;
            REP(i2, y[2].size()+1) {
                if (i2 > 0 && w0 + w1 + w2 + y[2][i2-1].first > w) break;
                if (i2 > 0) {
                    w2 += y[2][i2-1].first;
                    v2 += y[2][i2-1].second;
                }
                ll w3 = 0, v3 = 0;
                REP(i3, y[3].size()+1) {
                    if (i3 > 0 && w0 + w1 + w2 + w3 + y[3][i3-1].first > w) break;
                    if (i3 > 0) {
                        w3 += y[3][i3-1].first;
                        v3 += y[3][i3-1].second;
                    }
                    maxi = max(maxi, v0+v1+v2+v3);
                }
            }
        }
    }
    cout << maxi << '\n';

    return 0;
}
