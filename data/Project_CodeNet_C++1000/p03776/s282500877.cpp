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
#define repa(i,n) for (auto& i: n)

template<class T> inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
void init() {cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(15);}

#ifdef DEBUG
template <class T, class N> void verr(const T& a, const N& n) { rep(i, n) cerr << a[i] << " "; cerr << "\n" << flush; }
ll dbgt = 1; void err() { cerr << "passed " << dbgt++ << "\n" << flush; }
template<class H, class... T> void err(H&& h,T&&... t){ cerr<< h << (sizeof...(t)?" ":"\n") << flush; if(sizeof...(t)>0) err(forward<T>(t)...); }
#endif

const ll INF = 5e18;
const ld EPS = 1e-11;
const ld PI = acos(-1.0L);
const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;
//--------------------------------------------------------------------------------//

int main() {
    init();
    ll N, A, B;
    cin >> N >> A >> B;
    vl V(N);
    rep(i, N) cin >> V[i];
    sort(all(V), greater<ll>());

    ld sum = accumulate(V.begin(), V.begin() + A, 0ll);
    ld nowa = sum / A;
    ll vi = B;

    repe(i,A,B){
        ld tmpa = (nowa * i + V[i]) / (i + 1);
        // err(i, tmpa, nowa);
        if(nowa>tmpa){
            vi = i;
            break;
        }
    }

    ll ans = 0;
    repe(c,A-1,vi){
        ll v = V[c], vallcnt = count(all(V), V[c]), vcnt = count(V.begin(), V.begin() + c + 1, V[c]);
        ld cnt = 1;
        repe(i,1,vcnt + 1){
            cnt *= vallcnt - i + 1;
            cnt /= i;
        }
        ans += (ll)cnt;
        // err(vallcnt, vcnt, vi, ans, cnt);
    }

    cout << nowa << endl
         << ans << endl;
}