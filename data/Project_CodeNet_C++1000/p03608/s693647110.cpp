#include<bits/stdc++.h>
using namespace std;
#pragma region atcoder
//using mint = modint998244353;
//These are for segment tree
/*int op(int a, int b){return max(a, b);}
int e(){return -1;}
bool f(int v){ return v < target;}
*/
#pragma endregion
#pragma region macros
using ll = long long;
using vi = vector<int>;
using vs = vector<string>;
using vl = vector<ll>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rrep(i, n) for(int i = n - 1; i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
template<class T>bool chmax(T &a, const T b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T b) { if (b<a) { a=b; return 1; } return 0; }
template<class T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<class T> T lcm(T a,T b){return a / gcd(a, b) * b;}
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
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
 
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m, R; cin >> n >> m >> R;
    vi r(R);
    rep(i,R) cin >> r[i];
    vvl dist(n, vl(n, inf));
    for(int i = 0; i < n; i++) dist[i][i] = 0;
    rep(i,m){
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        dist[a][b] = c;
        dist[b][a] = c;
    }
    rep(k,n){
        rep(i,n){
            rep(j,n){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    ll ans = INF;
    //注意 : ソートしないといけません
    sort(all(r));
    do{
        //debug(r);
        ll tmp = 0;
        for(int i = 1; i < R; i++){
            tmp += dist[r[i] - 1][r[i - 1] - 1];
        }
        ans = min(ans, tmp);
    }while(next_permutation(all(r)));
    cout << ans << endl;
}