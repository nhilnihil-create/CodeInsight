#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,a,b) for (int i = a; i < (b); ++i)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define YY cout << "Yes" << endl
#define NN cout << "No" << endl
#define pint pair<int,int>
#define vi(v) rep(i,v.size())cin >> v[i]
#define vc(v) rep(i,v.size())cout << v[i] << endl
#define ni(n) cin >> n
#define nc(n) cout << n << endl
const int INF = 1000000007;
const long double EPS = 1e-15;
const long double PI = acos(-1);
typedef long long ll;
using namespace std;
using Graph = vector<vector<int>>;
using Graph_weighted = vector<vector<pair<int,int>>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
int G[1000][1000];
int solve(){
  int n,m,r;
  cin >> n >> m >> r;
  vector<int>v(r);
  rep(i,r){
    cin >> v[i];
    v[i]--;
  }
  sort(all(v));
  rep(i,n)rep(j,n){
    G[i][j] = INF;
    G[j][i] = INF;
  }
  rep(i,m){
    int a,b,c;
    cin >> a >> b >> c;
    a--,b--;
    G[a][b] = c;
    G[b][a] = c;
  }
  rep(k,n)rep(i,n)rep(j,n)G[i][j] = min(G[i][j],G[i][k] + G[k][j]);
  ll ans = INF;
  do{
    ll tmp = 0;
    rep(i,r - 1)tmp += G[v[i]][v[i + 1]];
    ans = min(ans,tmp);
  }while(next_permutation(all(v)));
  cout << ans << endl;
  return 0;
}
int main(){
  // ios::sync_with_stdio(false);cin.tie(nullptr);
  // cout << fixed;cout << setprecision(16);
  solve();
  return 0;
}
