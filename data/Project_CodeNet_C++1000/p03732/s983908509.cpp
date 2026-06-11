#include<bits/stdc++.h>
using namespace std;
#pragma region atcoder
/*#include <atcoder/dsu>
using namespace atcoder;*/
#pragma endregion
#pragma region macros
using ll = long long;
using vi = vector<int>;
using vs = vector<string>;
using vl = vector<ll>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vvc = vector<vector<char>>;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rrep(i, n) for(int i = n - 1; i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#pragma endregion
#pragma region debug for var, v, vv
#define debug(var)  do{std::cout << #var << " : ";view(var);}while(0)
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){cout << endl;int cnt = 0;for(const auto& v : vv){cout << cnt << "th : "; view(v); cnt++;} cout << endl;}
#pragma endregion
const ll mod = 1000000007;
const int inf = 1001001001;
const ll INF = 1001001001001001001;
const int MAX = 2000005;
template<class T>bool chmax(T &a, const T b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T b) { if (b<a) { a=b; return 1; } return 0; }
ll modpow(ll a, ll p){ll ret = 1; while(p){if(p & 1){ret = ret * a % mod;} a = a * a % mod; p >>= 1;} return ret;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

/*-----------------------------------------------------------------------------------------------------*/
ll dp[103][103][303];
int main(){
    ll N, W; cin >> N >> W;
    vl v(N), w(N);
    rep(i,N){
        cin >> w[i] >> v[i];
        if(i > 0) w[i] -= w[0];
    }
    ll base = w[0];
    w[0] = 0;
    rep(i, N){
        rep(j, i + 1){
            rep(k, 301){
                chmax(dp[i + 1][j][k],dp[i][j][k]);
                if(k - w[i] >= 0) chmax(dp[i + 1][j + 1][k], dp[i][j][k - w[i]] + v[i]);
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i <= N; i++){
        for(int j = 0; j < 301; j++){
            if(base * i + j <= W) chmax(ans, dp[N][i][j]);
        }
    }
    cout << ans << endl;
}