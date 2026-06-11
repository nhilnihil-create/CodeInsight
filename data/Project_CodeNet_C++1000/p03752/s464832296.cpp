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
const ll  MOD = 1000000007;
const double PI = acos(-1.0);
const double EPS = 1e-10;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
//template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    vector<ll> A(N);
    REP(i,N) cin >> A[i];
    ll ans = LINF;
    REP(bits,1<<N){
        if(__builtin_popcount(bits) != K) continue;
        ll tmp = 0;
        ll ma = 0;
        REP(j,N){
            if(bits >> j & 1){
                if(ma < A[j]) ma = A[j];
                else tmp += ma + 1 - A[j], ma++;
            }
            else chmax(ma, A[j]);
        }
        chmin(ans, tmp);
    }
    cout << ans << endl;
}