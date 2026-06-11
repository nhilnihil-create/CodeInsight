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
//const ll MOD = 1000000007;
const ll MOD = 998244353;
const double PI = acos(-1.0);
const double EPS = 1e-10;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
//template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};


void solve(){
    int N, K;
    cin >> N >> K;
    vector<int> A(N), B(N);
    REP(i,N) cin >> A[i] >> B[i];
    ll ans = 0;
    REP(i,N){
        bool ok = true;
        REP(j,30) if(!(K >> j & 1) && (A[i] >> j & 1)){
            ok = false;
            break;
        }
        if(ok) ans += B[i];
    }

    REP(i,30){
        if(K >> i & 1){
            ll c = K & ~(1LL << i);
            c |= (1LL << i) - 1;
            ll tmp = 0;
            REP(j,N){
                bool ok = true;
                REP(k,30){
                    if(!(c >> k & 1) && (A[j] >> k & 1)){
                        ok = false;
                        break;
                    }
                }
                if(ok) tmp += B[j];
            }
            chmax(ans, tmp);
        }
    }
    cout << ans << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    // int T; cin >> T; REP(t,T) solve();
}