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

int n;

int main() {
    cin >> n;
    Vs s(2);
    cin >> s[0] >> s[1];

    Vi v; char c = s[0][0];
    int i = 1;
    if (n == 1) v.push_back(0);
    while (i < n) {
        if (c == s[0][i]) {
            v.push_back(1);
            if (i+1 >= n) break;
            c = s[0][i+1];
            i++;
        } else {
            v.push_back(0);
            c = s[0][i];
        }
        if (i+1 >= n) {
            v.push_back(0);
            break;
        }
        i++;
    }

    ll res = 1;
    if (v[0] == 0) res *= 3;
    else res *= 6;
    REP2(i, 1, v.size()) {
        if (v[i] == 0) {
            if (v[i-1] == 0) res *= 2;
        } else {
            if (v[i-1] == 0) res *= 2;
            else res *= 3;
        }
        res %= MOD;
    }
    cout << res << '\n';

    return 0;
}
