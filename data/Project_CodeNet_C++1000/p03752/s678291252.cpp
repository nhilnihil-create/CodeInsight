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
using Msi = M<string, int>;

#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define REP2(i,s,e) for(int i=(int)(s);i<(int)(e);++i)
#define RREP(i,s,e) for(int i=(int)(s);i>=(int)(e);--i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin(),ie=(c).end();i!=ie;++i)
#define ALL(c) (c).begin(), (c).end()

const double PI = acos(-1);
const ll MOD = 1e9+7;

int n, k;
string s;
Vl a;
V<bool> u;

ll dfs(int d) {
    if (d == n) {
        int cnt = 0;
        REP(i, n) cnt += u[i] ? 1 : 0;
        if (cnt < k) return 1e18;
        ll sum = 0;
        ll maxi = a[0];
        REP2(i, 1, n) {
            if (u[i]) {
                if (a[i] <= maxi) sum += maxi - a[i] + 1;
                maxi++;
            }
            maxi = max(maxi, a[i]);
        }
        return sum;
    }
    u[d] = true;
    ll x = dfs(d+1);
    u[d] = false;
    ll y = dfs(d+1);
    return min(x, y);
}

int main() {
    cin >> n >> k;
    a = Vl(n);
    REP(i, n) cin >> a[i];

    u = V<bool>(n, false);
    u[0] = true;
    std::cout << dfs(1) << '\n';

    return 0;
}
