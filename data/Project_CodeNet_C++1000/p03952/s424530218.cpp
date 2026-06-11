#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
template<class T> using vc = vector<T>;
template<class T> using vvc = vector<vector<T>>;

const ll MOD = 1e9 + 7;
const ll INF = 1e16;
const ld EPS = 1e-11;
const ld PI = acos(-1.0L);
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define repr(i, n) for (ll i = (n)-1; i >= 0; i--)
#define repe(i, l, r) for (ll i = (l); i < (r); i++)
#define reper(i, l, r) for (ll i = (r)-1; i >= (l); i--)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

void init() {cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(15);}
//--------------------------------------------------------------------------------//

int main() {
    init();
    ll N, x;
    cin >> N >> x;
    ll un = 2 * N - 1;

    if(un==2&&x==2){
        cout << "Yes" << endl
             << 1 << endl
             << 2 << endl
             << 3 << endl;
        return 0;
    }else if(x==1||x==un){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;

    ll li = 1, ri = 1;
    vc<ll> l = {x - 1}, r = {x + 1};
    if (x - 2 > 0) r.eb(x - 2), ri++;
    if (x + 2 <= un - 1) l.eb(x + 2), li++;
    queue<ll> q;
    repe(i, 1, x - 2) q.emplace(i);
    repe(i, x + 1 + li, un + 1) q.emplace(i);

    while(li<N-1){
        ll a = q.front();
        q.pop();
        l.eb(a);
        li++;
    }
    while(ri<N-1){
        ll a = q.front();
        q.pop();
        r.eb(a);
        ri++;
    }

    reverse(all(l));
    rep(i, N - 1) cout << l[i] << "\n";
    cout << x << "\n";
    rep(i, N - 1) cout << r[i] << "\n";
}