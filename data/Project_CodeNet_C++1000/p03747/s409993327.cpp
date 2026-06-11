#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define bit(n) (1<<(n))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}
int const INF = 1001001001;


int main()
{
    ll n,L,T;
    cin >> n >> L >> T;
    vl x(n),w(n);
    rep(i,n) cin >> x[i] >> w[i];

    vl z(n);
    rep(i,n) {
        if(w[i] == 1) z[i] = (x[i] + T) % L;
        if(w[i] == 2) z[i] = ((x[i] - T) % L + L) % L;
    }
    vl v;
    if(w[0] == 1) {
        for(int i = 1; i < n; ++i) {
            if(w[i] == 2) v.push_back(x[i]-x[0]);
        }
    }
    if(w[0] == 2) {
        for(int i = n-1; i > 0; --i) {
            if(w[i] == 1) v.push_back(L-x[i]+x[0]);
        }
    }
    ll p = (2*T)/L, q = (2*T)%L;
    ll collide_count = p*SZ(v);
    rep(j,SZ(v)) {
        if(v[j] <= q) collide_count++;
    }

    // 蟻rがz[0]にいる
    // 蟻rと重なっている蟻がいるとき(その位置をyとおく)
    // w[0] = 1 ⇒ 蟻rの位置は右側のy
    // w[0] = 2 ⇒ 蟻rの位置は左側のy
    ll r, y = z[0];
    if(w[0] == 1) r = collide_count % n;
    if(w[0] == 2) r = n - collide_count % n;
    sort(z.begin(), z.end());

    //蟻rがz[pos]にいる(zはsort済み)
    ll pos;
    if(w[0] == 1) {
        rep(i,n) {
            if(z[i] == y) pos = i;
        }
    }
    if(w[0] == 2) {
        drep(i,n) {
            if(z[i] == y) pos = i;
        }
    }
    // 蟻0がz[base]にいる
    ll base = ((pos + n) - r) % n;
    rotate(z.begin(), z.begin() + base, z.end());

    rep(i,n) cout << z[i] << endl;
    return 0;
}