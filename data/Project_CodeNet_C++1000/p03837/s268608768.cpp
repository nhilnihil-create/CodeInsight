#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(i) begin(i), end(i)

const int INF = 0x3fffffff;
const ll MINF = 0x7fffffffffff;
const ld DINF = numeric_limits<ld>::infinity();
const int MOD = 1000000007;
const int MODD = 998244353;
const ld EPS = 1e-9;
const ld PI = 3.1415926535897932;

template<class T> bool chmin(T &a, const T &b){ if(a > b){ a = b; return 1; } else return 0; }
template<class T> bool chmax(T &a, const T &b){ if(a < b){ a = b; return 1; } else return 0; }
template<class T> auto min(const T& a){ return *min_element(all(a)); }
template<class T> auto max(const T& a){ return *max_element(all(a)); }

ll gcd(ll a, ll b){ while(b){ ll c = b; b = a % b; a = c; } return a; }
ll lcm(ll a, ll b){ if(!a || !b) return 0; return a * b / gcd(a, b); }
ll pow_mod(ll n,ll k,ll m){ll r = 1;for(; k > 0;k >>= 1) {if (k & 1) r = (r * n) % m; n = (n * n) % m;}return r;}


//ここから。
int main(){
    int N,M;
    cin >> N >> M;
    vector<vector<int>> dist(N,vector<int> (N,INF));
    vector<vector<bitset<1000>>> memo(N,vector<bitset<1000>>(N,0));
    
    rep(i,M){
        int a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        dist[a][b] = c;
        dist[b][a] = c;
        memo[a][b][i] = 1;
        memo[b][a][i] = 1;
    }
    rep(i,N) dist[i][i] = 0;
    rep(k,N)
        rep(j,N)
            rep(i,N){
                if(dist[j][i] > dist[j][k] + dist[k][i]){
                    dist[j][i] = dist[j][k] + dist[k][i];
                    memo[j][i] = memo[j][k] | memo[k][i];
                }
            }
    
    bitset<1000> ans = 0,test = 0;
    rep(i,N){
        rep(j,N){
            ans |= memo[i][j];
        }
    }
    int cnt = ans.count();
    cout << M - cnt << endl;
}