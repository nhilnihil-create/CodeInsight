#include <bits/stdc++.h>
#define rep(i, start, end) for (long long i = start; i < end; ++i)
#define repreverse(i, start, end) for (long long i = start; i >= end; --i)
#define all(x) (x).begin(), (x).end()
#define len(x) ((long long)(x).size())
#define g(a, b) __gcd((a), (b))
#define l(a, b) ((a) / __gcd((a), (b)) * (b))
using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vllvll = vector<vll>;
using pll = pair<ll, ll>;
template<class T>void print1d(T x,ll n=-1){if(n==-1)n=x.size();rep(i,0,n){cout<<x[i]<<' ';}cout<<'\n';}
template<class T>void print2d(T x,ll r=-1,ll c=-1){if(r==-1)r=x.size();if(c==-1)c=x[0].size();rep(i,0,r)print1d(x[i],c);}
template<class T, class U>bool haskey(T mp, U key) { return mp.find(key) != mp.end(); }
template<class T, class U>bool isin(T el, U container) { return find(all(container), el) != container.end(); }
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
template<class T, class U>T rem(T a, U b) { return a - b*floor(a/b); }
template<class T>ld deg2rad(T deg) { return M_PI * deg / 180.0; }
template<class T>ld rad2deg(T rad) { return 180.0 * rad / M_PI; }
const long double pi = M_PI;
const long long big = 1LL << 50;
const long long inf = 1LL << 60;
const long long mod = 1e9 + 7;


int main()
{
    ll N, M, R;
    cin >> N >> M >> R;
    vllvll Graph(N+1, vll(N+1, inf));

    vll r(R);
    rep(i, 0, R) cin >> r[i];
    rep(i, 0, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        Graph[a][b] = c;
        Graph[b][a] = c;
    }


    rep(k, 1, N+1) {
            rep(i, 1, N+1) {
                    rep(j, 1, N+1) {
                            Graph[i][j] = min(Graph[i][j], Graph[i][k] + Graph[k][j]);
                    }
            }
    }

    sort(all(r));
    ll ans = inf;
    do {
            ll sm = 0;
            rep(i, 0, R-1) {
                    sm += Graph[r[i]][r[i+1]];
            }
            chmin(ans, sm);
    } while (next_permutation(all(r)));

    cout << ans << endl;
}

