#include <bits/stdc++.h>
 
using namespace std;
 
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl;
#define DEBUG_MAT(v) cerr<<#v<<endl;for(int i=0;i<v.size();i++){for(int j=0;j<v[i].size();j++) {cerr<<v[i][j]<<" ";}cerr<<endl;}
typedef long long ll;
// #define int ll
 
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
template<class S, class T> pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first + t.first, s.second + t.second); }
template<class S, class T> pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first - t.first, s.second - t.second); }
template<class S, class T> ostream& operator<<(ostream& os, pair<S, T> p) { os << "(" << p.first << ", " << p.second << ")"; return os; }
#define X first
#define Y second
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(int)(n);i>0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(),c.end()
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = (ll)1e18 + 1;
const long double pi = 3.1415926535897932384626433832795028841971L;
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl;
// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
vi dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
// vi dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
const ll MOD = 1000000007;
// const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'


signed main() {
    fio();
    ll n, l, t;
    cin >> n >> l >> t;

    vector<pll> xw(n);
    rep (i, n) {
        cin >> xw[i].first >> xw[i].second;
        xw[i].second--;
    }

    ll col = 0;
    rep (i, n) {
        if (xw[i].second != xw[0].second) {
            ll ori_dist;
            if (xw[0].second == 0) {
                ori_dist = xw[i].first - xw[0].first;
            }
            else {
                ori_dist = xw[0].first - xw[i].first + l;
            }
            
            if (t * 2 >= ori_dist) {
                col++;
                ll t2 = 2 * t - ori_dist;
                col += t2 / l;
            }
        }
    }
    DEBUG(col);

    vector<pll> xi(n);
    rep (i, n) {
        xi[i].second = i;
        ll x2;
        if (xw[i].second == 0) x2 = xw[i].first + t;
        else x2 = xw[i].first - t;
        x2 = (x2 % l + l) % l;
        xi[i].first = x2;
    }
    sort(all(xi), [&](pll xi1, pll xi2) {
        if (xi1.first != xi2.first) return xi1.first < xi2.first;
        int i = xi1.second, j = xi2.second;
        return xw[i].second == 1;
    });

    int idx;
    rep (i, n) {
        if (xi[i].second == 0) {
            idx = i;
            break;
        }
    }

    vl ans(n);
    int i;
    if (xw[0].second == 0) {
        i = ((i + col % n) % n + n) % n;
    }
    else {
        i = ((i - col % n) % n + n) % n;
    }

    rep (_, n) {
        ans[i] = xi[idx].first;
        i = (i + 1) % n;
        idx = (idx + 1) % n;
    }

    rep (i, n) {
        cout << ans[i] << endl;
    }
}