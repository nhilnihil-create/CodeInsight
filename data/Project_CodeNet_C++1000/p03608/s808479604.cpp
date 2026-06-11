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

int n, m, r;

int main() {
    cin >> n >> m >> r;
    Vi rl(r);
    REP(i, r) {
        cin >> rl[i];
        rl[i]--;
    }

    VVi d(n, Vi(n, 1e9));
    REP(i, m) {
        int a,b,c; cin >> a >> b >> c; a--; b--;
        d[a][b] = c;
        d[b][a] = c;
    }

    REP(k, n) REP(i, n) REP(j, n) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }

    int mini = 1e9;
    Vi p(r);
    REP(i, r) p[i] = i;
    do {
        int sum = 0;
        REP(i, r-1) {
            sum += d[rl[p[i]]][rl[p[i+1]]];
        }
        mini = min(mini, sum);
    } while( next_permutation(ALL(p)) );

    cout << mini << '\n';

    return 0;
}
