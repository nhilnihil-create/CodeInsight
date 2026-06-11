#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
template<class T> using vc = vector<T>;
template<class T> using vvc = vector<vector<T>>;

const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;
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
    ll N,L;
    cin >> N >> L;
    vl A(N);
    rep(i, N) cin >> A[i];
    bool isok = false;
    ll m;
    rep(i,N-1){
        if(A[i]+A[i+1]>=L){
            isok = true;
            m = i+1;
            break;
        }
    }
    if(!isok){
        cout << "Impossible" << endl;
        return 0;
    }

    cout << "Possible" << "\n";
    repe(i, 1, m) cout << i << "\n";
    reper(i, m + 1, N) cout << i << "\n";
    cout << m << "\n";
}