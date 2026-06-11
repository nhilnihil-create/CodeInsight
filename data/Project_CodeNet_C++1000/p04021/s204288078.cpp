#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
template<class T> using vc = vector<T>;
template<class T> using vvc = vector<vector<T>>;

#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define repr(i, n) for (ll i = (n)-1; i >= 0; i--)
#define repe(i, l, r) for (ll i = (l); i < (r); i++)
#define reper(i, l, r) for (ll i = (r)-1; i >= (l); i--)
#define repa(i, n) for (auto& i: n)

template<class T> inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
void init() {cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(15);}

#ifdef DEBUG
template <class T, class N> void verr(const T& a, const N& n) { rep(i, n) cout << a[i] << " "; cout << "\n"; }
ll dbgt = 1; void err() { cout << "passed " << dbgt++ << "\n"; }
template<class H, class... T> void err(H&& h,T&&... t){ cout<< h << (sizeof...(t)?" ":"\n"); if(sizeof...(t)>0) err(forward<T>(t)...); }
#endif

const ll INF = 5e18;
const ld EPS = 1e-11;
const ld PI = acos(-1.0L);
const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;
//--------------------------------------------------------------------------------//

int main() {
    init();
    ll N;
    cin >> N;
    vl A(N);
    repa(i, A) cin >> i;

    vl B = A, D(N);
    sort(all(B));

    rep(i, N) D[i] = lower_bound(all(B), A[i]) - B.begin();

    ll cnt = 0;
    rep(i, N) if (abs(D[i] - i) % 2) cnt++;

    cout << cnt / 2 << endl;
}