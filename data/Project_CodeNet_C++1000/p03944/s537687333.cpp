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
template<class T>ld deg2rad(T deg) { return M_PI * deg / 180.0; }
template<class T>ld rad2deg(T rad) { return 180.0 * rad / M_PI; }
const long double pi = M_PI;
const long long big = 1LL << 50;
const long long inf = 1LL << 60;
const long long mod = 1e9 + 7;

ll W, H, N;
vllvll grid;

void paintx(ll sx, ll gx)
{
        rep(i, 0, H) {
                rep(j, sx, gx) {
                        grid[i][j] = 1;
                }
        }
}

void painty(ll sy, ll gy)
{
        rep(i, sy, gy) {
                rep(j, 0, W) {
                        grid[i][j] = 1;
                }
        }
}

int main()
{
        cin >> W >> H >> N;
        grid.resize(H, vll(W, 0));
        rep(i, 0, N) {
                ll x, y, a;
                cin >> x >> y >> a;
                if (a == 1) paintx(0, x);
                if (a == 2) paintx(x, W);
                if (a == 3) painty(0, y);
                if (a == 4) painty(y, H);
        }
        ll cnt = 0;
        rep(i, 0, H) {
                rep(j, 0, W) {
                        if (grid[i][j] == 0) ++cnt;
                }
        }
        //print2d(grid);
        cout << cnt << endl;
}