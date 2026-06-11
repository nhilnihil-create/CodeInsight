#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <stack>
#include <string>
#include <vector>
 
using namespace std;
typedef long long ll;
using gra = vector<vector<ll>>;
using gram = vector<unordered_map<ll,ll>>;
 
typedef unsigned long long ull;
 
template <class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
template <class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
 
template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template <class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template <class T> T dup(T a, T b) { return (a + b - 1) / b; }
template <class T> T modpow(T x, T p, T m) { T a=1; while(p){ if(p%2)a =a*x%m; x = x+x%m; p/=2; } return a; }
// template <class T> void prim(T a) { for(ll i=0;i<a.size();++i) { cout << a[i]; } cout << "\n"; }
 
#define mod 1000000007LL
#define INF 10000000000000000LL
 
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep1(i, n) for (int i = 1; i <= n; ++i)
#define rrep(i, n) for (int i = (n - 1); i >= 0; --i)
#define rrep1(i, n) for (int i = n; i > 0; --i)
 
#define pri(x) cout << (x) << "\n"
#define pri2(x, y) cout << (x) << " " << (y) << "\n"
#define pri3(x, y, z) cout << (x) << " " << (y) << " " << (z) << "\n"
//#define modpow(x, p, m) { ll a=1; while(p){ if(p%2)a =a*x%m; x = x+x%m; p/=2; } return a; }
 
#define m0(h) memset(h, 0, sizeof(h))
#define m1(h) memset(h, 1, sizeof(h))
#define m(h, n) memset(h, (n), sizeof(h))
#define all(n) (n).begin(),(n).end()
#define bit(n) (1LL << (n))
#define pb push_back
 
//#ifdef LOCAL
//
//#define dpri(...) fprintf(stderr, __VA_ARGS__)
//#define pria(g) rep(i,g.size()){ cout << i << "{"; rep(j,g[i].size()) cout << g[i][j] << " "; cout << "}" << "\n"; }
//#else
//#define dpri(...) 42
//#define pria(g) 42
//#endif
 
 
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // ---------------------
  // コーディング開始
  // ---------------------
  ll n,w;
  cin >> n >> w;
  ll o,v;
  
  // 何個目か何個選んだか重さ
  ll dp[n+1][n+1][3*n];
  m0(dp);
  ll d = INF;
  rep(i,n){
    cin >> o >> v;
    if(d==INF)d=o;
    rep(j,n){
      rep(k,n*3){
        // 選ばなかった場合
        dp[i+1][j][k] = max(dp[i+1][j][k],dp[i][j][k]);
        // 選んだ場合
        if(w>=j*d+k+o)
          dp[i+1][j+1][k+o-d] = max(dp[i+1][j+1][k+o-d],dp[i][j][k]+v);
      }
    } 
  }
  ll ans =0;
  rep(j,n+1)
    rep(k,n*3)
      ans = max(ans,dp[n][j][k]);
  
  pri(ans);
  
  return 0;
}

