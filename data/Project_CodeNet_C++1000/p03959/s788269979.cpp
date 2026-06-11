#include <bits/stdc++.h>
//#define int long long

using namespace std;
using LL = long long;
using P = pair<int, int>;

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)

#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()

template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>
auto make_v(size_t a, Ts... ts) {return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...)); }

template<typename T,typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T &t, const V &v){ t = v; }

template<typename T,typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T &t, const V &v){ for(auto &e : t) fill_v(e, v); }

const int INF = (int)1e9;
const LL INFL = (LL)1e18;
const int MOD = 1e9 + 7;

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<int> t(n), a(n);
    REP(i, n) cin >> t[i];
    REP(i, n) cin >> a[i];

    vector<bool> c(n), d(n);
    c[0] = true;
    d[n-1] = true;
    REP(i, n-1) if(t[i] != t[i+1]) c[i+1] = true;
    REP(i, n-1) if(a[n-i-1] != a[n-i-2]) d[n-i-2] = true;

    LL ans = 1;
    REP(i, n) if(c[i] && d[i]) if(t[i] != a[i]) ans = 0;
    REP(i, n) if(c[i]) if(t[i] > a[i]) ans = 0;
    REP(i, n) if(d[i]) if(t[i] < a[i]) ans = 0;

    REP(i, n)
    {
        if(!c[i] && !d[i])
        {
            ans = ans * min(t[i], a[i]) % MOD;
        }
    }
    cout << ans << endl;
}