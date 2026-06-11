#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define ll long long
using namespace std;
//typedef vector<unsigned int>vec;
//typedef vector<ll>vec;
//typedef vector<vec> mat;
typedef pair<int, int> P;
typedef pair<ll,ll> LP;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int INF = 1000000000;
const ll LINF = 1000000000000000000;//1e18
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
const double PI = acos(-1.0);
const double EPS = 1e-10;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
//template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};

template <class Abel> struct BIT {
    const Abel UNITY_SUM = 0;                       // to be set
    vector<Abel> dat;

    /* [1, n] */
    BIT(int n) : dat(n + 1, UNITY_SUM) { }
    void init(int n) { dat.assign(n + 1, UNITY_SUM); }

    /* a is 1-indexed */
    inline void add(int a, Abel x) {
        for (int i = a; i < (int)dat.size(); i += i & -i)
            dat[i] = dat[i] + x;
    }

    /* [1, a], a is 1-indexed */
    inline Abel sum(int a) {
        Abel res = UNITY_SUM;
        for (int i = a; i > 0; i -= i & -i)
            res = res + dat[i];
        return res;
    }

    /* [a, b), a and b are 1-indexed */
    inline Abel sum(int a, int b) {
        return sum(b - 1) - sum(a - 1);
    }

    /* debug */
    void print() {
        for (int i = 1; i < (int)dat.size(); ++i) cout << sum(i, i + 1) << ",";
        cout << endl;
    }
};

void solve(){
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N);
    REP(i,N) cin >> a[i];
    vector<ll> cum(N+1);
    REP(i,N) cum[i+1] = cum[i] + (a[i] - K);
    vector<ll> b = cum;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    BIT<ll> bit(N+10);
    ll ans = 0;
    for(int i=0;i<=N;i++){
        int idx = lower_bound(b.begin(), b.end(), cum[i]) - b.begin();
        ans += bit.sum(idx+1);
        bit.add(idx+1, 1);
    }
    cout << ans << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    // int T; cin >> T; REP(t,T) solve();
}