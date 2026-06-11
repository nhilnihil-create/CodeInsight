#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#define ll long long
#define ld long double

#define rep(i, n) for(ll i = 0; i < n; ++i)
#define rep2(i, a, b) for(ll i = a; i <= b; ++i)
#define rrep(i, a, b) for(ll i = a; i >= b; --i)

#define pii pair<int, int>
#define pll pair<ll, ll>

#define fi first
#define se second

#define pb push_back
#define eb emplace_back

#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pii>
#define vpll vector<pll>
#define all(a) a.begin(), a.end()

#define endl '\n'
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
  
const int MOD=1e9+7;
const ll INF=1e18;
const double PI=acos(-1);
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,-1,1,1,-1};
 
const int MAX=510000;

int dist[110][110];
int a[1000],b[1000],c[1000];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
   
  int n, m;
  cin >> n >> m;
  
  rep(i,n)rep(j,n) dist[i][j]=MOD;
  rep(i,n)dist[i][i]=0;
  
  rep(i,m){
    cin >> a[i] >> b[i] >> c[i];
    a[i]--;
    b[i]--;
    
    chmin(dist[a[i]][b[i]],c[i]);
    chmin(dist[b[i]][a[i]],c[i]);
    
  }
  rep(k,n)rep(i,n)rep(j,n){
    chmin(dist[i][j],dist[i][k]+dist[k][j]);
  }
  
  int ans = m;
  rep(i,m){
    bool ok = false;
    rep(j,n) if(dist[j][a[i]]+c[i] == dist[j][b[i]]) ok = true;
    if(ok)ans--;
  }
  
  cout << ans << endl;
  return 0;
}
